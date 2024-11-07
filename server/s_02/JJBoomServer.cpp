#include "JJBoomServer.h"


JJBoomServer::JJBoomServer(unsigned int msg_head_size, int port) :
	TcpServer(msg_head_size, port)
{
	_do_thread = nullptr;

	std::string s;
	_str_rand(s);
}

JJBoomServer::~JJBoomServer()
{
	if (_do_thread)
	{
		_do_thread->shutdown();
		delete _do_thread;
		_do_thread = nullptr;
	}
}

void JJBoomServer::_start(int thread_num_head, int message_deal_thread)
{
	_do_thread = new ThreadPool(2);
	_do_thread->start();

	_thread_heartbeat = new ThreadPool();
	_thread_heartbeat->start();
	_thread_heartbeat->_post_func([&]() { _jjchat_heartbeat(); });

	TcpServer::_start(thread_num_head, message_deal_thread);
}

// ----------------------------------------------------
void JJBoomServer::_deal_head_msg(Client* client)
{
	jjboom::message_header header;
	header.SerializeFromCString(client->get_buff(), client->head_size());

	
	size_t body_size = header.get_body_size();
	if (body_size == 0)
	{
		switch (header.get_msg_type())
		{
		case jjboom::message_header::MASSAGE_TYPE::MSG_GET_SIGN_UP_SALT:
			_do_thread->_post_func([&]() {_do_MSG_GET_SIGN_UP_SALT(client); });
			break;
		default:
			break;
		}
		_final_read(client);
		return;
	}

	char* _body = new char[body_size];
	memset(_body, 0, body_size);

	_read(_body, body_size, client, std::bind(&JJBoomServer::_deal_msg, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, header.get_msg_type()));

}

void JJBoomServer::_deal_msg(char* read_buf, Client* client, unsigned int size, jjboom::message_header::MASSAGE_TYPE type)
{
	std::shared_ptr<std::string> str_ptr = std::make_shared<std::string>(read_buf, size);

	switch (type)
	{
	case jjboom::message_header::MASSAGE_TYPE::MSG_LOGIN:
		_do_thread->_post_func([=]() {_do_LOGIN(str_ptr, client); });
		break;
	case jjboom::message_header::MASSAGE_TYPE::MSG_LOGOUT:
		
		break;
	case jjboom::message_header::MASSAGE_TYPE::MSG_SIGN_UP:
		_do_thread->_post_func([=]() {_do_MSG_SIGN_UP(str_ptr, client); });
		break;
	case jjboom::message_header::MASSAGE_TYPE::MSG_GET_SIGN_IN_SALT:
		_do_thread->_post_func([=]() {_do_GET_SIGN_IN_SALT(str_ptr, client); });
		break;
	case jjboom::message_header::MASSAGE_TYPE::MSG_GET_FRIENDS_GROUPS:
		_do_thread->_post_func([=]() {_do_MSG_GET_FRIENDS_GROUPS(str_ptr, client); });
		break;
	default:
		break;
	}



	if (read_buf)
	{
		delete[] read_buf;
		read_buf = nullptr;
	}
	_final_read(client);
}

void JJBoomServer::_str_rand(std::string& str, int len)
{
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(33, 126);
	// ascii 33~126   126-33=93
	str.resize(len);
	char t;
	for (int i = 0; i < len; ++i)
	{
		t = dist(mt);
		str[i] = t;
	}
}

void JJBoomServer::_to_md5(std::string& value, const char* data, size_t data_len)
{
	value.clear();
	unsigned char cstr_md5[MD5_DIGEST_LENGTH];
	MD5(reinterpret_cast<const unsigned char*>(data), data_len, cstr_md5);
	for (size_t i = 0; i < MD5_DIGEST_LENGTH; ++i)
	{
		value += char0x[cstr_md5[i] / 16];
		value += char0x[cstr_md5[i] % 16];
	}
}

void JJBoomServer::_jjchat_heartbeat(unsigned int sleep_time)
{
	while (!_server_close)
	{
		// 心跳间隔
		std::this_thread::sleep_for(std::chrono::seconds(sleep_time));

		std::string str_header;
		for (auto client : _clients)
		{
			if (client)
			{
				get_header_str(str_header, jjboom::message_header::MASSAGE_TYPE::MSG_SERVER_HEARTBEAT);
			}
			_write(str_header, nullptr, 0, client);
		}
		for (auto it = _map_jjchat_id_clients.begin(); it != _map_jjchat_id_clients.end(); it++)
		{
			if (it->second->client == nullptr)
			{
				std::unique_lock<std::mutex> lock(_mutex_map);
				_map_jjchat_id_clients.erase(it->first);
			}
		}
	}
}

void JJBoomServer::get_header_str(std::string& str_header, jjboom::message_header::MASSAGE_TYPE msg_type)
{
	jjboom::message_header header;
	header.set_msg_type(msg_type);
	header.set_body_size(0);
	header.SerializeToString(str_header);
}

void JJBoomServer::_do_MSG_GET_SIGN_UP_SALT(Client* client)
{
	std::string salt;
	_str_rand(salt, 5);

	jjboom::message_get_sign_up_salt_back get_sign_up_salt_back;
	get_sign_up_salt_back.set_salt(salt);
	std::string str_get_sign_up_salt_back;
	std::string str_header;
	get_header_body_str(str_header, jjboom::message_header::MASSAGE_TYPE::MSG_GET_SIGN_UP_SALT_BACK, str_get_sign_up_salt_back, get_sign_up_salt_back);

	_write(str_header, str_get_sign_up_salt_back, client);
}

void JJBoomServer::_do_MSG_SIGN_UP(std::shared_ptr<std::string> str, Client* client)
{
	jjboom::message_sign_up sign_up;
	sign_up.SerializeFromString(*str.get());
	std::string salt2;
	_str_rand(salt2, 5);

	std::string password = sign_up.get_user_pwd() + salt2;
	_to_md5(password, password.c_str(), password.size());

	std::string username = sign_up.get_user_name();
	std::string salt1 = sign_up.get_salt();

	jjboom::message_sign_up_back sign_up_back;
	std::string str_sign_up_back;
	std::string str_header;

	sign_up_back.set_is_success(true);
	unsigned long long user_id = my_mysql_connect::InStance().sign_up(username, password, salt1, salt2);
	if (0 == user_id)
	{
		// The error code will likely report a syntax error
		std::cout << "Operation failed with error code: " << my_mysql_connect::InStance().get_err_code() << '\n';
		// diag.server_message() will contain the classic phrase
		// "You have an error in your SQL syntax; check the manual..."
		// Bear in mind that server_message() may contain user input, so treat it with caution
		std::cout << "Server diagnostics: " << my_mysql_connect::InStance().get_diagnostics().server_message() << std::endl;

		sign_up_back.set_is_success(false);
	}
	std::string time;
	if (sign_up_back.get_is_success())
	{
		int ec = my_mysql_connect::InStance().get_user_sign_up_time(time, user_id);
		if (ec)
		{
			time = "get time err";
		}
	}
	sign_up_back.set_sign_up_id(user_id);
	sign_up_back.set_sign_up_time(time);
	get_header_body_str(str_header, jjboom::message_header::MASSAGE_TYPE::MSG_SIGN_UP_BACK, str_sign_up_back, sign_up_back);
	_write(str_header, str_sign_up_back, client);

	// 创建相关数据库表
	if (my_mysql_connect::InStance().create_user_other_table(user_id))
	{
		std::cout << "Operation failed with error code: " << my_mysql_connect::InStance().get_err_code() << '\n';
		std::cout << "Server diagnostics: " << my_mysql_connect::InStance().get_diagnostics().server_message() << std::endl;
	}
}

void JJBoomServer::_do_GET_SIGN_IN_SALT(std::shared_ptr<std::string> str, Client* client)
{
	jjboom::message_get_sign_in_salt_back get_sign_in_salt_back;
	std::string str_header;
	std::string str_get_sign_in_salt_back;
	jjboom::message_get_sign_in_salt get_sign_in_salt;
	if (-1 == get_sign_in_salt.SerializeFromString(*str.get()))
	{
		get_header_body_str(str_header, jjboom::message_header::MASSAGE_TYPE::MSG_GET_SIGN_IN_SALT_BACK, str_get_sign_in_salt_back, get_sign_in_salt_back);
		_write(str_header, str_get_sign_in_salt_back, client);
		return;
	}
	
	std::string salt;
	if (my_mysql_connect::InStance().get_user_salt1(get_sign_in_salt.get_user_id(), salt))
	{
		std::cout << "Operation failed with error code: " << my_mysql_connect::InStance().get_err_code() << '\n';
		std::cout << "Server diagnostics: " << my_mysql_connect::InStance().get_diagnostics().server_message() << std::endl;
	}
	get_sign_in_salt_back.set_salt(salt);
	
	get_header_body_str(str_header, jjboom::message_header::MASSAGE_TYPE::MSG_GET_SIGN_IN_SALT_BACK, str_get_sign_in_salt_back, get_sign_in_salt_back);
	_write(str_header, str_get_sign_in_salt_back, client);
}

void JJBoomServer::_do_LOGIN(std::shared_ptr<std::string> str, Client* client)
{
	jjboom::message_login_back login_back;
	login_back.set_is_success(false);
	std::string str_header;
	std::string str_login_back;
	jjboom::message_login login;
	if (-1 == login.SerializeFromString(*str.get()))
	{
		return;
	}
	std::string salt2;
	if (my_mysql_connect::InStance().get_user_salt2(login.get_user_id(), salt2))
	{
		std::cout << "Operation failed with error code: " << my_mysql_connect::InStance().get_err_code() << '\n';
		std::cout << "Server diagnostics: " << my_mysql_connect::InStance().get_diagnostics().server_message() << std::endl;
		login_back.set_cookie_code("server error");
		return;
	}
	std::string password = login.get_user_pwd() + salt2;
	_to_md5(password, password.c_str(), password.size());
	std::string server_password;
	if (my_mysql_connect::InStance().get_user_password(login.get_user_id(), server_password))
	{
		std::cout << "Operation failed with error code: " << my_mysql_connect::InStance().get_err_code() << '\n';
		std::cout << "Server diagnostics: " << my_mysql_connect::InStance().get_diagnostics().server_message() << std::endl;
		login_back.set_cookie_code("server error");
		return;
	}
	if (password != server_password)
	{
		login_back.set_cookie_code("password not right");
		return;
	}

	std::string cookie_code;
	_str_rand(cookie_code, 20);
	login_back.set_cookie_code(cookie_code);
	login_back.set_is_success(true);

	get_header_body_str(str_header, jjboom::message_header::MASSAGE_TYPE::MSG_LOGIN_BACK, str_login_back, login_back);
	if (-1 == _write(str_header, str_login_back, client))
	{
		return;
	}

	JJBoomServer::jjchat_client* jjclient = new JJBoomServer::jjchat_client();
	jjclient->client = client;
	jjclient->cookie_code = cookie_code;
	auto itr = _map_jjchat_id_clients.find(login.get_user_id());
	if (itr != _map_jjchat_id_clients.end())
	{
		// 此账号已登录，将原登录挤掉线
		// 向 client 发送一条掉线消息
		jjboom::message_server_disconnect server_disconnect;
		server_disconnect.set_reason("账号在别处登录");
		std::string str_server_disconnect;
		get_header_body_str(str_header, jjboom::message_header::MASSAGE_TYPE::MSG_SERVER_DISCONNECT, str_server_disconnect, server_disconnect);
		_write(str_header, str_server_disconnect, client);

		std::cout << "顶号: " << itr->first << "\n";
		_remove_client(itr->second->client);
		
		std::unique_lock<std::mutex> lock(_mutex_map);
		_map_jjchat_id_clients.erase(itr);
	}
	_mutex_map.lock();
	auto pair = _map_jjchat_id_clients.insert({ login.get_user_id() , jjclient });
	_mutex_map.unlock();
	if (!pair.second)
	{
		std::cout << "map_jjchat_id_clients insert error : " << pair.first->first << "\n";
	}

}

void JJBoomServer::_do_MSG_GET_FRIENDS_GROUPS(std::shared_ptr<std::string> str, Client* client)
{
	jjboom::message_get_friends_groups get_friends_groups;
	jjboom::message_get_friends_groups_back get_friends_groups_back;
	jjboom::message_server_disconnect server_disconnect;
	std::string str_header;
	std::string str_get_friends_groups_back;
	std::string str_server_disconnect;
	if (get_friends_groups.SerializeFromString(*str.get()))
	{
		std::cout << "数据错误 client: " << client << "\n";
		server_disconnect.set_reason("");
		return;
	}
	auto itr = _map_jjchat_id_clients.find(get_friends_groups.get_user_id());
	if (itr == _map_jjchat_id_clients.end() || itr->second->cookie_code != get_friends_groups.get_user_cookie_code())
	{
		server_disconnect.set_reason("Permission verification failed");
		get_header_body_str(str_header, jjboom::message_header::MASSAGE_TYPE::MSG_SERVER_DISCONNECT, str_server_disconnect, server_disconnect);
		_write(str_header, str_server_disconnect, client);
		_remove_client(client);
		return;
	}
	std::vector<std::shared_ptr<friends_groups_element>> friends;
	std::vector<std::shared_ptr<friends_groups_element>> groups;
	if (my_mysql_connect::InStance().get_user_friends(get_friends_groups.get_user_id(), friends, groups))
	{
		std::cout << "Operation failed with error code: " << my_mysql_connect::InStance().get_err_code() << '\n';
		std::cout << "Server diagnostics: " << my_mysql_connect::InStance().get_diagnostics().server_message() << std::endl;

		return;
	}
	for (auto& user_friend : friends)
	{
		get_friends_groups_back.set_back_type(jjboom::message_get_friends_groups_back::TYPE::TYPE_FRIEND_OFFLINE);
		if (_map_jjchat_id_clients.find(user_friend->id) != _map_jjchat_id_clients.end())
		{
			get_friends_groups_back.set_back_type(jjboom::message_get_friends_groups_back::TYPE::TYPE_FRIEND_ONLINE);
		}
		get_friends_groups_back.set_other_id(user_friend->id);
		get_friends_groups_back.set_other_name(user_friend->name);
		get_friends_groups_back.set_join_time(user_friend->create_time);

		get_header_body_str(str_header, jjboom::message_header::MASSAGE_TYPE::MSG_GET_FRIENDS_GROUPS_BACK, str_get_friends_groups_back, get_friends_groups_back);
		if (-1 == _write(str_header, str_get_friends_groups_back, client))
		{
			_map_jjchat_id_clients.erase(get_friends_groups.get_user_id());
			return;
		}
	}

	for (auto& user_group : groups)
	{
		get_friends_groups_back.set_back_type(jjboom::message_get_friends_groups_back::TYPE::TYPE_GROUP);
		get_friends_groups_back.set_other_id(user_group->id);
		get_friends_groups_back.set_other_name(user_group->name);
		get_friends_groups_back.set_join_time(user_group->create_time);

		get_header_body_str(str_header, jjboom::message_header::MASSAGE_TYPE::MSG_GET_FRIENDS_GROUPS_BACK, str_get_friends_groups_back, get_friends_groups_back);
		if (-1 == _write(str_header, str_get_friends_groups_back, client))
		{
			_map_jjchat_id_clients.erase(get_friends_groups.get_user_id());
			return;
		}
	}

}

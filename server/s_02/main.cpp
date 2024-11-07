

#include "JJBoomServer.h"

#include "JSON/jjchat_json.h"





int main()
{
	jjchat_init init;
	std::string json_err;
	if (!jjchat_json::get_jjchat_init(json_err, "./jjchat.json", init))
	{
		std::cout << json_err << std::endl;
		init.mysql.database = "jjchat";
		init.mysql.password = "123456";
		init.mysql.server_host = "127.0.0.1";
		init.mysql.username = "root";
		init.server.port = 10240;
	}

	std::string database_err;
	if (!my_mysql_connect::InStance().connect(database_err, init.mysql.username.c_str(), init.mysql.password.c_str(), init.mysql.server_host.c_str(), init.mysql.database.c_str()))
	{
		std::cout << database_err << "\n";
		return -1;
	}

	jjboom::message_header h;
	std::string str;

	JJBoomServer* server = new JJBoomServer(h.SerializeToString(str), init.server.port);

	bool is_running = true;
	std::thread cmd([&]() {
		std::string cmd;
		while (is_running)
		{
			std::cin >> cmd;
			//std::cout << cmd;
			if (cmd == std::string("exit"))
			{
				server->stop();
				break;
			}
			std::cout << "if you want to stop the server please input \"exit\" \n";
		}
		});

	cmd.detach();
	server->_start(1, 2);
	is_running = false;

	/*std::thread tcp([&]() {
		server->_start(1,2);
		});
	tcp.detach();*/


	delete server;
	server = nullptr;

	return 0;
}
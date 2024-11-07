#ifndef GAME_SERVER
#define GAME_SERVER


#include "NET/_server.h"
#include "NET/_message.h"

#include "my_mysql_connect.h"

#include "_msg_struct.h"

#include "msg_header.potato.h"
#include "jjchat_msg.potato.h"

#include <openssl/md5.h>

#include <random>
#include <memory>
#include <map>
#include <chrono>
#include <iostream>



class JJBoomServer : public TcpServer
{
public:
	JJBoomServer(unsigned int msg_head_size, int port = 10240);
	~JJBoomServer();
	
	void _start(int thread_num_head = 1, int message_deal_thread = 1);
protected:
	void _deal_head_msg(Client* client) override;
	void _deal_msg(char* read_buf, Client* client, unsigned int size, jjboom::message_header::MASSAGE_TYPE type);

	void _str_rand(std::string& str, int len = 5);
	void _to_md5(std::string& value, const char* data, size_t data_len);

	// second
	void _jjchat_heartbeat(unsigned int sleep_time = 15);

	/*
	* out
	* in
	* out
	* in
	*/
	template<typename T>
	void get_header_body_str(std::string& str_header
							, jjboom::message_header::MASSAGE_TYPE msg_type
							, std::string& str_body
							, T& body);

	void get_header_str(std::string& str_header
		, jjboom::message_header::MASSAGE_TYPE msg_type);

public:
	struct jjchat_client {
		jjchat_client()
			: client(nullptr)
		{}
		std::string cookie_code;
		Client* client;
	};

private:
	void _do_MSG_GET_SIGN_UP_SALT(Client* client);
	void _do_MSG_SIGN_UP(std::shared_ptr<std::string> str, Client* client);
	void _do_GET_SIGN_IN_SALT(std::shared_ptr<std::string> str, Client* client);
	void _do_LOGIN(std::shared_ptr<std::string> str, Client* client);
	void _do_MSG_GET_FRIENDS_GROUPS(std::shared_ptr<std::string> str, Client* client);

private:
	std::mutex _mutex_map;
	std::map<unsigned long long, jjchat_client*> _map_jjchat_id_clients;

	const char char0x[17]{ "THISPAWORDNICBZF" };
	ThreadPool* _do_thread;
	ThreadPool* _thread_heartbeat;

};



template<typename T>
inline void JJBoomServer::get_header_body_str(std::string& str_header, jjboom::message_header::MASSAGE_TYPE msg_type, std::string& str_body, T& body)
{
	jjboom::message_header header;
	header.set_msg_type(msg_type);
	header.set_body_size(body.SerializeToString(str_body));
	header.SerializeToString(str_header);
}


#endif // !GAME_SERVER

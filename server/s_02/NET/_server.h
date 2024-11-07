
#ifndef _SERVER_
#define _SERVER_

#include "boost/asio.hpp"


#include <iostream>

#include <functional>
#include <vector>
#include <memory>
#include <system_error>

#include "../DATA_WORK/_thread_pool.h"

//class _server;

class _client_context 
{
public:

	_client_context(boost::asio::io_service &service, unsigned int read_head_buf_size):
		_sock(service),
		_read_head_buf_size(read_head_buf_size),
		_read_head_buf(new char[read_head_buf_size])
	{
		memset(_read_head_buf, 0, _read_head_buf_size);
	}

	~_client_context()
	{
		if (_read_head_buf)
		{
			delete[] _read_head_buf;
			_read_head_buf = nullptr;
		}
	}

	char* get_buff()
	{
		return _read_head_buf;
	}
	
	void clear_buff()
	{
		memset(_read_head_buf, 0, _read_head_buf_size);
	}

	boost::asio::ip::tcp::socket& get_sock()
	{
		return _sock;
	}

	unsigned int head_size()
	{
		return _read_head_buf_size;
	}

	void close()
	{
		_sock.close();
	}


private:
	boost::asio::ip::tcp::socket _sock;
	char* _read_head_buf;
	unsigned int _read_head_buf_size;
};
typedef _client_context Client;





class _server
{

public:
	
	// msg_hand_size: 消息头长度 
	// msg_len:		 _read_buff 长度
	// port:		 端口号
	_server(unsigned int msg_head_size, int port = 10240) :
		_msg_head_size(msg_head_size),
		_thread_num(1),
		_port(port),
		_accept_client(new Client(_service, msg_head_size)),
		_threads_header(nullptr),
		_threads_msg(nullptr),
		_send_thread(new ThreadPool()),
		_acceptor(_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)),
		_sending(false),
		_server_close(false)
	{
		
	}

	void stop()
	{
		_server_close = true;
		_service.stop();
	}

	virtual ~_server()
	{
		_server_close = true;
		_close_threads();
		_close();
	}

	//从此开始
	void _start(int thread_num_head = 1, int message_deal_thread = 1)
	{
		_thread_num = thread_num_head;
		_threads_header = new ThreadPool(thread_num_head);
		_threads_header->start();

		_threads_msg = new ThreadPool(message_deal_thread);
		_threads_msg->start();
		_send_thread->start();

		_acceptor.async_accept(_accept_client->get_sock(), std::bind(&_server::_have_accept, this, _accept_client, std::placeholders::_1));
		_service.run();
	}


protected:


	//发送数据
	int _write(const char* header, size_t size_header, const char* body, size_t size_body, Client* client)
	{
		std::unique_lock<std::mutex> lock(_mutex);

		if (nullptr == client)
		{
			return -1;
		}
		// if not header
		if (nullptr == header || 0 == size_header)
		{
			return 0;
		}
		char* _write_header = new char[size_header];
		for (size_t i = 0; i < size_header; ++i)
		{
			_write_header[i] = header[i];
		}
		_send_thread->_post_func(std::bind(&_server::_send, this, _write_header, size_header, client));
		// if not body
		if (nullptr == body || 0 == size_body)
		{
			return 0;
		}
		char* _write_str = new char[size_body];
		for (size_t i = 0; i < size_body; ++i)
		{
			_write_str[i] = body[i];
		}
		_send_thread->_post_func(std::bind(&_server::_send, this, _write_str, size_body, client));

		return 0;
	}

	int _write(const char* header, size_t size_header, const std::string& body, Client* client)
	{
		std::unique_lock<std::mutex> lock(_mutex);

		if (nullptr == client)
		{
			return -1;
		}
		// if not header
		if (nullptr == header || 0 == size_header)
		{
			return 0;
		}
		char* _write_header = new char[size_header];
		for (size_t i = 0; i < size_header; ++i)
		{
			_write_header[i] = header[i];
		}
		_send_thread->_post_func(std::bind(&_server::_send, this, _write_header, size_header, client));
		size_t size_body = body.size();
		// if not body
		if (0 == size_body)
		{
			return 0;
		}
		char* _write_str = new char[size_body];
		for (size_t i = 0; i < size_body; ++i)
		{
			_write_str[i] = body[i];
		}
		_send_thread->_post_func(std::bind(&_server::_send, this, _write_str, size_body, client));

		return 0;
	}

	int _write(const std::string& header, const char* body, size_t size_body, Client* client)
	{
		std::unique_lock<std::mutex> lock(_mutex);

		if (nullptr == client)
		{
			return -1;
		}
		size_t size_header = header.size();
		// if not header
		if (0 == size_header)
		{
			return 0;
		}
		char* _write_header = new char[size_header];
		for (size_t i = 0; i < size_header; ++i)
		{
			_write_header[i] = header[i];
		}
		_send_thread->_post_func(std::bind(&_server::_send, this, _write_header, size_header, client));
		// if not body
		if (nullptr == body || 0 == size_body)
		{
			return 0;
		}
		char* _write_str = new char[size_body];
		for (size_t i = 0; i < size_body; ++i)
		{
			_write_str[i] = body[i];
		}
		_send_thread->_post_func(std::bind(&_server::_send, this, _write_str, size_body, client));
		return 0;
	}

	int _write(const std::string& header, const std::string& body, Client* client)
	{
		std::unique_lock<std::mutex> lock(_mutex);

		if (nullptr == client)
		{
			return -1;
		}
		size_t size_header = header.size();
		// if not header
		if (0 == size_header)
		{
			return 0;
		}
		char* _write_header = new char[size_header];
		for (size_t i = 0; i < size_header; ++i)
		{
			_write_header[i] = header[i];
		}
		_send_thread->_post_func(std::bind(&_server::_send, this, _write_header, size_header, client));
		size_t size_body = body.size();
		// if not body
		if (0 == size_body)
		{
			return 0;
		}
		char* _write_str = new char[size_body];
		for (size_t i = 0; i < size_body; ++i)
		{
			_write_str[i] = body[i];
		}
		_send_thread->_post_func(std::bind(&_server::_send, this, _write_str, size_body, client));
		return 0;
	}

	
	//消息头处理函数
	virtual void _deal_head_msg(Client*) = 0;

	void _send(char* write_str, size_t size, Client* client)
	{
		if (nullptr == client)
		{
			return;
		}

		while (_sending)
		{
			if (_server_close) break;
		}
		_sending = true;
		boost::asio::async_write(client->get_sock(), boost::asio::buffer(write_str, size), std::bind(&_server::_send_complete, this, std::placeholders::_1, std::placeholders::_2, write_str, client));


	}

	void _send_complete(const std::error_code& err, size_t bytes, char* write_str, Client* client)
	{
		_sending = false;
		if (write_str)
		{
			delete[] write_str;
			write_str = nullptr;
		}
		if (err)
		{
			_remove_client(client);
		}
	}


	//读取 
	//func 读取完成后调用回调函数（参数为<char*>的缓冲区指针和Client指针）
	//read_buf 缓冲区指针 size 需要读取的数据长度（一般在消息头取得）
	int _read(char* read_buf, unsigned int size, Client* client, std::function<void(char*,Client*, unsigned int)> func)
	{
		if (nullptr == client)
		{
			return -1;
		}
		boost::asio::async_read(client->get_sock()
			, boost::asio::buffer(read_buf, size)
			, std::bind(&_server::_callback_deal_func, this, std::placeholders::_1, std::placeholders::_2, client, func, read_buf, size));
		return 0;
	}

	void _callback_deal_func(const std::error_code& err, size_t bytes, Client* client, std::function<void(char*, Client*, unsigned int)> func, char* read_buf, unsigned int size)
	{
		if (err)
		{
			std::cout << "read error\n";
			_remove_client(client);
			return;
		}
		if (func)
		{
			_threads_msg->_post_func(std::bind(func, read_buf, client, size));
		}
		//func(read_buf, client, size);

	}

	void _have_accept(Client* client, const std::error_code& err)
	{

		_add_client(client);

		_read_header(client, _msg_head_size);
		Client* _new_client = new Client(_service, _msg_head_size);
		_acceptor.async_accept(_new_client->get_sock(), std::bind(&_server::_have_accept, this, _new_client, std::placeholders::_1));
	}

	int _read_header(Client* client, unsigned int size)
	{
		if (client)
		{
			client->clear_buff();
			boost::asio::async_read(client->get_sock()
				, boost::asio::buffer(client->get_buff(), size)
				, std::bind(&_server::_read_head_complete, this, std::placeholders::_1, std::placeholders::_2, client));
			return 0;
		}
		return -1;

	}

	void _read_head_complete(const std::error_code& err, size_t bytes, Client* client)
	{
		if (err)
		{
			_remove_client(client);

			return;
		}

		_threads_header->_post_func(std::bind(&_server::_deal_head_msg, this, client));
	}




	//post async read head again, do this func when you deal your task.
	void _final_read(Client* client)
	{
		_read_header(client, _msg_head_size);
	}

	void _add_client(Client* client)
	{
		std::unique_lock<std::mutex> lock(_mutex_clients);
		_clients.push_back(client);
	}

	void _remove_client(Client* client)
	{
		if (nullptr == client)
		{
			return;
		}
		for (int i = 0; i <= _clients.size(); ++i)
		{
			if (client == _clients[i])
			{
				std::unique_lock<std::mutex> lock(_mutex_clients);

				client->close();
				delete client;
				client = nullptr;
				_clients[i] = _clients.back();
				_clients.pop_back();
				return;
			}
		}
	}

	void _close_threads()
	{
		if (_threads_header)
		{
			_threads_header->shutdown();
			delete _threads_header;
			_threads_header = nullptr;
		}
		if (_send_thread)
		{
			_send_thread->shutdown();
			delete _send_thread;
			_send_thread = nullptr;
		}
		if (_threads_msg)
		{
			_threads_msg->shutdown();
			delete _threads_msg;
			_threads_msg = nullptr;
		}
	}

	void _close()
	{
		if (!_clients.empty())
		{
			for (auto& it : _clients)
			{
				if (it)
				{
					delete it;
					it = nullptr;
				}
			}
			_clients.clear();
		}

	}
protected:
	
	std::vector<Client*> _clients;

	boost::asio::io_service _service;
	boost::asio::ip::tcp::acceptor _acceptor;
	Client* _accept_client;

	std::mutex _mutex;
	std::mutex _mutex_clients;

	//线程池 消息头处理线程
	ThreadPool* _threads_header;
	//线程池 消息处理线程 默认不开启，开启时为空线程池，队列中无要运行的函数
	ThreadPool* _threads_msg;
	//发送线程
	ThreadPool* _send_thread;

	unsigned int _msg_head_size;
	int _thread_num;
	int _port;

	bool _sending;
	bool _server_close;

};
typedef _server TcpServer;



















#endif // !_SERVER_

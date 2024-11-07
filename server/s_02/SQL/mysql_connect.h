#ifndef MYSQL_CONNECT
#define MYSQL_CONNECT


#include <boost/mysql.hpp>
#include <string>



class mysql_connect
{
public:
	mysql_connect();
	virtual ~mysql_connect();

	bool connect(std::string& err, const char* username, const char* password, const char* server_hostname, const char* database);
	bool execute(std::string& str_err, const char* sql, boost::mysql::results& result);

protected:
	// The execution context, required to run I/O operations.
	boost::asio::io_context ctx;
	// The SSL context, required to establish TLS connections.
	// The default SSL options are good enough for us at this point.
	boost::asio::ssl::context ssl_ctx;
	// Represents a connection to the MySQL server.
	boost::mysql::tcp_ssl_connection conn;
};


#endif // !MYSQL_CONNECT


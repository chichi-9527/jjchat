#include "mysql_connect.h"

mysql_connect::mysql_connect() :
	ssl_ctx(boost::asio::ssl::context::tls_client),
	conn(ctx.get_executor(), ssl_ctx)
{}

mysql_connect::~mysql_connect()
{
    // Close the connection
    conn.close();
}

bool mysql_connect::connect(std::string& str_err, const char* username, const char* password, const char* server_hostname, const char* database)
{
    str_err.clear();
    // Resolve the hostname to get a collection of endpoints
    boost::asio::ip::tcp::resolver resolver(ctx.get_executor());
    auto endpoints = resolver.resolve(server_hostname, boost::mysql::default_port_string);

    // The username, password and database to use
    boost::mysql::handshake_params params(username, password, database);

    try
    {
        // Connect to the server using the first endpoint returned by the resolver
        conn.connect(*endpoints.begin(), params);
    }
    catch (const boost::mysql::error_with_diagnostics& err)
    {
        str_err.append("Error: ").append(err.what()).append("\n").append("Server diagnostics: ").append(err.get_diagnostics().server_message());
        return false;
    }
    catch (const std::exception& err)
    {
        str_err.append("Error: ").append(err.what());
        return false;
    }
    
    return true;;
}

bool mysql_connect::execute(std::string& str_err, const char* sql, boost::mysql::results& result)
{
    str_err.clear();
    boost::mysql::error_code ec;
    boost::mysql::diagnostics diag;
    conn.execute(sql, result, ec, diag);
    if (ec)
    {
        str_err.append("Operation failed with error code : ").append(std::to_string(ec.value())).append("\n")
            .append("Server diagnostics: ").append(diag.server_message());
        
        return false;
    }
    return true;
}

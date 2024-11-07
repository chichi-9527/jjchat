#ifndef JJCHAT_JSON
#define JJCHAT_JSON

#include <boost/json.hpp>

#include <fstream>
#include <string>
#include <system_error>


struct jjchat_init
{
	struct MySQL
	{
		std::string username;
		std::string password;
		std::string server_host;
		std::string database;
	};
	struct Server
	{
		int port;
	};
	MySQL mysql;
	Server server;
};

class jjchat_json 
{
public:
	static bool get_jjchat_init(std::string& str_err,const char* json_path, jjchat_init& init)
	{
		std::filebuf fb;
		if (fb.open(json_path, std::ios::in))
		{
			std::istream is(&fb);
			std::error_code ec;
			boost::json::object obj;
			obj = boost::json::parse(is, ec).as_object();
			if (ec)
			{
				str_err.append("json parse err : ").append(ec.message());
				return false;
			}
			
			if (obj.contains("mysql"))
			{
				if (obj.at("mysql").as_object().contains("username"))
				{
					init.mysql.username = obj.at("mysql").as_object().at("username").as_string().c_str();
				}
			}

			if (obj.contains("mysql"))
			{
				if (obj.at("mysql").as_object().contains("password"))
				{
					init.mysql.password = obj.at("mysql").as_object().at("password").as_string().c_str();
				}
			}

			if (obj.contains("mysql"))
			{
				if (obj.at("mysql").as_object().contains("server_host"))
				{
					init.mysql.server_host = obj.at("mysql").as_object().at("server_host").as_string().c_str();
				}
			}

			if (obj.contains("mysql"))
			{
				if (obj.at("mysql").as_object().contains("database"))
				{
					init.mysql.database = obj.at("mysql").as_object().at("database").as_string().c_str();
				}
			}

			if (obj.contains("server"))
			{
				if (obj.at("server").as_object().contains("port"))
				{
					init.server.port = (int)obj.at("server").as_object().at("port").as_int64();
				}
			}

			return true;
			
		}
		
		str_err.append("file open err");
        return false;
	}
};



#endif // !JJCHAT_JSON

#include "my_mysql_connect.h"

my_mysql_connect& my_mysql_connect::InStance()
{
	static my_mysql_connect _my_mysql_connect;
	return _my_mysql_connect;
}

boost::mysql::error_code& my_mysql_connect::get_err_code()
{
	return _ec;
}

boost::mysql::diagnostics& my_mysql_connect::get_diagnostics()
{
	return _diag;
}

unsigned long long my_mysql_connect::sign_up(std::string& name, std::string& pwd, std::string& salt1, std::string& salt2)
{
	boost::mysql::statement stmt = conn.prepare_statement(STR_INSERT_SIGN_UP);
	boost::mysql::results result;
	conn.execute(stmt.bind(name.c_str(), pwd.c_str(), salt1.c_str(), salt2.c_str()), result, _ec, _diag);
	if (_ec)
	{
		return 0;
	}
	if (result.has_value())
	{
		return result.last_insert_id();
	}
	return 0;
}

int my_mysql_connect::get_user_sign_up_time(std::string& str_time, unsigned long long id)
{
	str_time.clear();
	boost::mysql::statement stmt = conn.prepare_statement(STR_GET_USER_SIGN_UP_DATETIME);
	boost::mysql::results result;
	conn.execute(stmt.bind(std::to_string(id)), result, _ec, _diag);
	if (_ec)
	{
		return -1;
	}
	boost::mysql::datetime datetime;
	try
	{
		datetime = result.rows().at(0).at(0).as_datetime();
	}
	catch (std::out_of_range)
	{
		return -2;
	}
	catch (boost::mysql::bad_field_access)
	{
		return -3;
	}
	str_time = std::to_string(datetime.year())
		+ "-" + std::to_string(datetime.month())
		+ "-" + std::to_string(datetime.day())
		+ " " + std::to_string(datetime.hour())
		+ ":" + std::to_string(datetime.minute())
		+ ":" + std::to_string(datetime.second());
	return 0;
}

int my_mysql_connect::create_user_other_table(unsigned long long id)
{
	boost::mysql::results result;
	std::string str_sql;
	str_sql = std::string(STR_CREATE_USER_MAESSAGE_TABLE1) + std::to_string(id) + std::string(STR_CREATE_USER_MAESSAGE_TABLE2);
	conn.execute(str_sql, result, _ec, _diag);
	if (_ec)
	{
		return -1;
	}
	str_sql.clear();
	str_sql = std::string(STR_CREATE_USER_FRIENDS_TABLE1) + std::to_string(id) + std::string(STR_CREATE_USER_FRIENDS_TABLE2);
	conn.execute(str_sql, result, _ec, _diag);
	if (_ec)
	{
		return -1;
	}
	return 0;
}


int my_mysql_connect::get_user_salt1(unsigned long long id, std::string& salt)
{
	boost::mysql::results result;
	boost::mysql::statement stmt = conn.prepare_statement(STR_GET_USER_SALT1);
	conn.execute(stmt.bind(std::to_string(id)), result, _ec, _diag);
	if (_ec)
	{
		return -1;
	}
	try
	{
		salt = result.rows().at(0).at(0).as_string();
	}
	catch (std::out_of_range)
	{
		return -2;
	}
	catch (boost::mysql::bad_field_access)
	{
		return -3;
	}
	return 0;
}

int my_mysql_connect::get_user_salt2(unsigned long long id, std::string& salt)
{
	boost::mysql::results result;
	boost::mysql::statement stmt = conn.prepare_statement(STR_GET_USER_SALT2);
	conn.execute(stmt.bind(std::to_string(id)), result, _ec, _diag);
	if (_ec)
	{
		return -1;
	}
	try
	{
		salt = result.rows().at(0).at(0).as_string();
	}
	catch (std::out_of_range)
	{
		return -2;
	}
	catch (boost::mysql::bad_field_access)
	{
		return -3;
	}
	return 0;
}

int my_mysql_connect::get_user_password(unsigned long long id, std::string& password)
{
	boost::mysql::results result;
	boost::mysql::statement stmt = conn.prepare_statement(STR_GET_USER_SALT2);
	conn.execute(stmt.bind(std::to_string(id)), result, _ec, _diag);
	if (_ec)
	{
		return -1;
	}
	try
	{
		password = result.rows().at(0).at(0).as_string();
	}
	catch (std::out_of_range)
	{
		return -2;
	}
	catch (boost::mysql::bad_field_access)
	{
		return -3;
	}
	return 0;
}

int my_mysql_connect::get_user_friends(unsigned long long id, 
	std::vector<std::shared_ptr<friends_groups_element>>& friends, 
	std::vector<std::shared_ptr<friends_groups_element>>& groups)
{
	boost::mysql::results result;
	std::string str_sql;
	str_sql = std::string(STR_GET_USER_FRIENDS1) + std::to_string(id) + std::string(STR_GET_USER_FRIENDS2);
	boost::mysql::execution_state st;
	conn.start_execution(str_sql, st, _ec, _diag);
	if (_ec)
	{
		return -1;
	}
	while (!st.complete())
	{
		boost::mysql::rows_view row_batch = conn.read_some_rows(st);
		for (auto post : row_batch)
		{
			try
			{
				auto element = std::make_shared<friends_groups_element>();
				auto datetime = post.at(2).as_datetime();
				element->create_time = std::to_string(datetime.year()) + "-" + std::to_string(datetime.month()) + "-" + std::to_string(datetime.day());
				element->name = post.at(3).as_string();
				element->id = post.at(1).as_int64();
				if (1 == post.at(0).as_int64())
				{
					// friend
					friends.push_back(element);
				}
				else
				{
					// group
					groups.push_back(element);
				}
			}
			catch (std::out_of_range)
			{
				return -2;
			}
			catch (boost::mysql::bad_field_access)
			{
				return -3;
			}
		}
	}
	return 0;
}

my_mysql_connect::my_mysql_connect()
{}

my_mysql_connect::~my_mysql_connect()
{}

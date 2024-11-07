#ifndef MY_MYSQL_CONNECT
#define MY_MYSQL_CONNECT

#define STR_INSERT_SIGN_UP "INSERT INTO users(name, sign_up_time, password, salt1, salt2)\
							VALUES(? , now(), ?, ?, ?);"

#define STR_GET_INSERT_LAST_ID "SELECT LAST_INSERT_ID();"

#define STR_GET_USER_SIGN_UP_DATETIME "SELECT sign_up_time FROM users WHERE user_id = ?;"

#define STR_CREATE_USER_MAESSAGE_TABLE1			 "CREATE TABLE message_people_"
#define STR_CREATE_USER_MAESSAGE_TABLE2			"(	`message_id` bigint UNSIGNED NOT NULL AUTO_INCREMENT,	\
`message_type` int NOT NULL,	\
`people_group_id` bigint NOT NULL,	\
`message_data` varchar(255) NOT NULL,	\
`is_read` int NOT NULL DEFAULT 0,	\
`message_time` datetime NOT NULL,	\
PRIMARY KEY(`message_id`),	\
INDEX `s_is_read`(`is_read`) USING HASH	\
); "

#define STR_CREATE_USER_FRIENDS_TABLE1			"CREATE TABLE user_"
#define STR_CREATE_USER_FRIENDS_TABLE2			"_friends  ( `type` int NOT NULL DEFAULT 0,	`friend_group_id` bigint NOT NULL); "

#define STR_GET_USER_SALT1 "SELECT salt1 FROM users where user_id = ? ;"

#define STR_GET_USER_SALT2 "SELECT salt2 FROM users where user_id = ? ;"

#define STR_GET_USER_PASSWORD "SELECT password FROM users where user_id = ? ;"

#define STR_GET_USER_FRIENDS1 "SELECT \
table_1.type, \
table_1.friend_group_id, \
table_1.create_time, \
users.name \
FROM \
user_"
#define STR_GET_USER_FRIENDS2 "_friends AS table_1, \
users \
WHERE \
users.user_id = table_1.friend_group_id"


#include "SQL/mysql_connect.h"

#include <vector>
#include <memory>

struct friends_groups_element {
	friends_groups_element()
		: id(0)
	{}
	unsigned long long id;
	std::string name;
	std::string create_time;
};

class my_mysql_connect final : public mysql_connect
{
public:
	static my_mysql_connect& InStance();
	boost::mysql::error_code& get_err_code();
	boost::mysql::diagnostics& get_diagnostics();

	// ·µ»Ø 0 Ê±·¢ËÍ´íÎó
	unsigned long long sign_up(std::string& name, std::string& pwd, std::string& salt1, std::string& salt2);
	int get_user_sign_up_time(std::string& str_time, unsigned long long id);
	int create_user_other_table(unsigned long long id);
	/*
	*  id : in
	*  salt : out
	*/
	int get_user_salt1(unsigned long long id, std::string& salt);
	int get_user_salt2(unsigned long long id, std::string& salt);
	int get_user_password(unsigned long long id, std::string& password);
	int get_user_friends(unsigned long long id, 
		std::vector<std::shared_ptr<friends_groups_element>>& friends,
		std::vector<std::shared_ptr<friends_groups_element>>& groups);

protected:
	my_mysql_connect();
	my_mysql_connect(const my_mysql_connect&) = delete;
	const my_mysql_connect& operator=(const my_mysql_connect&) = delete;

	virtual ~my_mysql_connect();

private:
	boost::mysql::error_code _ec;
	boost::mysql::diagnostics _diag;
};


#endif // !MY_MYSQL_CONNECT


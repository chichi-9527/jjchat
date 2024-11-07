#include "jjchat_msg.potato.h"

size_t jjboom::message_login::SerializeToString(std::string& str)
{
	size_t str_len = OVERALL_STR_LENGTH(user_pwd.size());
	str.resize(str_len);

	ADD_TO_STR(user_id);
	STR_ADD_TO_STR(user_pwd);

	_add_len = 0;
	return str_len;
}

char* jjboom::message_login::SerializeToCString(size_t& len)
{
	len = OVERALL_STR_LENGTH(user_pwd.size());
	_c_data = new char[len];

	ADD_TO_CSTR(user_id);
	STR_ADD_TO_CSTR(user_pwd);

	_add_len = 0;
	return _c_data;
}

int jjboom::message_login::SerializeFromString(std::string& str)
{
	POP_FROM_STR(user_id);
	STR_POP_FROM_STR(user_pwd);

	IS_STR_ERR();
	return 0;
}

int jjboom::message_login::SerializeFromCString(char* c_str, size_t len)
{
	std::string str(c_str, len);
	return SerializeFromString(str);
}

ADD_MSG_ACHIEVE_HAVE_NAMESPACE(P_UINT64,user_id, message_login, jjboom)

ADD_MSG_STRING_ACHIEVE_HAVE_NAMESPACE(user_pwd, message_login, jjboom)

size_t jjboom::message_login_back::SerializeToString(std::string& str)
{
	size_t str_len = OVERALL_STR_LENGTH(cookie_code.size());
	str.resize(str_len);

	ADD_TO_STR(is_success);
	STR_ADD_TO_STR(cookie_code);

	_add_len = 0;
	return str_len;
}

char* jjboom::message_login_back::SerializeToCString(size_t& len)
{
	len = OVERALL_STR_LENGTH(cookie_code.size());
	_c_data = new char[len];

	ADD_TO_CSTR(is_success);
	STR_ADD_TO_CSTR(cookie_code);

	_add_len = 0;
	return _c_data;
}

int jjboom::message_login_back::SerializeFromString(std::string& str)
{
	POP_FROM_STR(is_success);
	STR_POP_FROM_STR(cookie_code);

	IS_STR_ERR();
	return 0;
}

int jjboom::message_login_back::SerializeFromCString(char* c_str, size_t len)
{
	std::string str(c_str, len);
	return SerializeFromString(str);
}

ADD_MSG_ACHIEVE_HAVE_NAMESPACE(bool,is_success, message_login_back, jjboom)

ADD_MSG_STRING_ACHIEVE_HAVE_NAMESPACE(cookie_code, message_login_back, jjboom)

size_t jjboom::message_sign_up::SerializeToString(std::string& str)
{
	size_t str_len = OVERALL_STR_LENGTH(user_name.size(), user_pwd.size(), salt.size());
	str.resize(str_len);

	STR_ADD_TO_STR(user_name);
	STR_ADD_TO_STR(user_pwd);
	STR_ADD_TO_STR(salt);

	_add_len = 0;
	return str_len;
}

char* jjboom::message_sign_up::SerializeToCString(size_t& len)
{
	len = OVERALL_STR_LENGTH(user_name.size(), user_pwd.size(), salt.size());
	_c_data = new char[len];

	STR_ADD_TO_CSTR(user_name);
	STR_ADD_TO_CSTR(user_pwd);
	STR_ADD_TO_CSTR(salt);

	_add_len = 0;
	return _c_data;
}

int jjboom::message_sign_up::SerializeFromString(std::string& str)
{
	STR_POP_FROM_STR(user_name);
	STR_POP_FROM_STR(user_pwd);
	STR_POP_FROM_STR(salt);

	IS_STR_ERR();
	return 0;
}

int jjboom::message_sign_up::SerializeFromCString(char* c_str, size_t len)
{
	std::string str(c_str, len);
	return SerializeFromString(str);
}

ADD_MSG_STRING_ACHIEVE_HAVE_NAMESPACE(user_name, message_sign_up, jjboom)

ADD_MSG_STRING_ACHIEVE_HAVE_NAMESPACE(user_pwd, message_sign_up, jjboom)

ADD_MSG_STRING_ACHIEVE_HAVE_NAMESPACE(salt, message_sign_up, jjboom)

size_t jjboom::message_sign_up_back::SerializeToString(std::string& str)
{
	size_t str_len = OVERALL_STR_LENGTH(sign_up_time.size());
	str.resize(str_len);

	ADD_TO_STR(sign_up_id);
	ADD_TO_STR(is_success);
	STR_ADD_TO_STR(sign_up_time);

	_add_len = 0;
	return str_len;
}

char* jjboom::message_sign_up_back::SerializeToCString(size_t& len)
{
	len = OVERALL_STR_LENGTH(sign_up_time.size());
	_c_data = new char[len];

	ADD_TO_CSTR(sign_up_id);
	ADD_TO_CSTR(is_success);
	STR_ADD_TO_CSTR(sign_up_time);

	_add_len = 0;
	return _c_data;
}

int jjboom::message_sign_up_back::SerializeFromString(std::string& str)
{
	POP_FROM_STR(sign_up_id);
	POP_FROM_STR(is_success);
	STR_POP_FROM_STR(sign_up_time);

	IS_STR_ERR();
	return 0;
}

int jjboom::message_sign_up_back::SerializeFromCString(char* c_str, size_t len)
{
	std::string str(c_str, len);
	return SerializeFromString(str);
}

ADD_MSG_ACHIEVE_HAVE_NAMESPACE(P_UINT64,sign_up_id, message_sign_up_back, jjboom)

ADD_MSG_ACHIEVE_HAVE_NAMESPACE(bool,is_success, message_sign_up_back, jjboom)

ADD_MSG_STRING_ACHIEVE_HAVE_NAMESPACE(sign_up_time, message_sign_up_back, jjboom)

size_t jjboom::message_get_sign_up_salt_back::SerializeToString(std::string& str)
{
	size_t str_len = OVERALL_STR_LENGTH(salt.size());
	str.resize(str_len);

	STR_ADD_TO_STR(salt);

	_add_len = 0;
	return str_len;
}

char* jjboom::message_get_sign_up_salt_back::SerializeToCString(size_t& len)
{
	len = OVERALL_STR_LENGTH(salt.size());
	_c_data = new char[len];

	STR_ADD_TO_CSTR(salt);

	_add_len = 0;
	return _c_data;
}

int jjboom::message_get_sign_up_salt_back::SerializeFromString(std::string& str)
{
	STR_POP_FROM_STR(salt);

	IS_STR_ERR();
	return 0;
}

int jjboom::message_get_sign_up_salt_back::SerializeFromCString(char* c_str, size_t len)
{
	std::string str(c_str, len);
	return SerializeFromString(str);
}

ADD_MSG_STRING_ACHIEVE_HAVE_NAMESPACE(salt, message_get_sign_up_salt_back, jjboom)

size_t jjboom::message_get_sign_in_salt::SerializeToString(std::string& str)
{
	size_t str_len = OVERALL_STR_LENGTH();
	str.resize(str_len);

	ADD_TO_STR(user_id);

	_add_len = 0;
	return str_len;
}

char* jjboom::message_get_sign_in_salt::SerializeToCString(size_t& len)
{
	len = OVERALL_STR_LENGTH();
	_c_data = new char[len];

	ADD_TO_CSTR(user_id);

	_add_len = 0;
	return _c_data;
}

int jjboom::message_get_sign_in_salt::SerializeFromString(std::string& str)
{
	POP_FROM_STR(user_id);

	IS_STR_ERR();
	return 0;
}

int jjboom::message_get_sign_in_salt::SerializeFromCString(char* c_str, size_t len)
{
	std::string str(c_str, len);
	return SerializeFromString(str);
}

ADD_MSG_ACHIEVE_HAVE_NAMESPACE(P_UINT64,user_id, message_get_sign_in_salt, jjboom)

size_t jjboom::message_get_sign_in_salt_back::SerializeToString(std::string& str)
{
	size_t str_len = OVERALL_STR_LENGTH(salt.size());
	str.resize(str_len);

	STR_ADD_TO_STR(salt);

	_add_len = 0;
	return str_len;
}

char* jjboom::message_get_sign_in_salt_back::SerializeToCString(size_t& len)
{
	len = OVERALL_STR_LENGTH(salt.size());
	_c_data = new char[len];

	STR_ADD_TO_CSTR(salt);

	_add_len = 0;
	return _c_data;
}

int jjboom::message_get_sign_in_salt_back::SerializeFromString(std::string& str)
{
	STR_POP_FROM_STR(salt);

	IS_STR_ERR();
	return 0;
}

int jjboom::message_get_sign_in_salt_back::SerializeFromCString(char* c_str, size_t len)
{
	std::string str(c_str, len);
	return SerializeFromString(str);
}

ADD_MSG_STRING_ACHIEVE_HAVE_NAMESPACE(salt, message_get_sign_in_salt_back, jjboom)

size_t jjboom::message_server_disconnect::SerializeToString(std::string& str)
{
	size_t str_len = OVERALL_STR_LENGTH(reason.size());
	str.resize(str_len);

	STR_ADD_TO_STR(reason);

	_add_len = 0;
	return str_len;
}

char* jjboom::message_server_disconnect::SerializeToCString(size_t& len)
{
	len = OVERALL_STR_LENGTH(reason.size());
	_c_data = new char[len];

	STR_ADD_TO_CSTR(reason);

	_add_len = 0;
	return _c_data;
}

int jjboom::message_server_disconnect::SerializeFromString(std::string& str)
{
	STR_POP_FROM_STR(reason);

	IS_STR_ERR();
	return 0;
}

int jjboom::message_server_disconnect::SerializeFromCString(char* c_str, size_t len)
{
	std::string str(c_str, len);
	return SerializeFromString(str);
}

ADD_MSG_STRING_ACHIEVE_HAVE_NAMESPACE(reason, message_server_disconnect, jjboom)

size_t jjboom::message_logout::SerializeToString(std::string& str)
{
	size_t str_len = OVERALL_STR_LENGTH(user_cookie_code.size());
	str.resize(str_len);

	ADD_TO_STR(user_id);
	STR_ADD_TO_STR(user_cookie_code);

	_add_len = 0;
	return str_len;
}

char* jjboom::message_logout::SerializeToCString(size_t& len)
{
	len = OVERALL_STR_LENGTH(user_cookie_code.size());
	_c_data = new char[len];

	ADD_TO_CSTR(user_id);
	STR_ADD_TO_CSTR(user_cookie_code);

	_add_len = 0;
	return _c_data;
}

int jjboom::message_logout::SerializeFromString(std::string& str)
{
	POP_FROM_STR(user_id);
	STR_POP_FROM_STR(user_cookie_code);

	IS_STR_ERR();
	return 0;
}

int jjboom::message_logout::SerializeFromCString(char* c_str, size_t len)
{
	std::string str(c_str, len);
	return SerializeFromString(str);
}

ADD_MSG_ACHIEVE_HAVE_NAMESPACE(P_UINT64,user_id, message_logout, jjboom)

ADD_MSG_STRING_ACHIEVE_HAVE_NAMESPACE(user_cookie_code, message_logout, jjboom)

size_t jjboom::message_get_friends_groups::SerializeToString(std::string& str)
{
	size_t str_len = OVERALL_STR_LENGTH(user_cookie_code.size());
	str.resize(str_len);

	ADD_TO_STR(user_id);
	STR_ADD_TO_STR(user_cookie_code);

	_add_len = 0;
	return str_len;
}

char* jjboom::message_get_friends_groups::SerializeToCString(size_t& len)
{
	len = OVERALL_STR_LENGTH(user_cookie_code.size());
	_c_data = new char[len];

	ADD_TO_CSTR(user_id);
	STR_ADD_TO_CSTR(user_cookie_code);

	_add_len = 0;
	return _c_data;
}

int jjboom::message_get_friends_groups::SerializeFromString(std::string& str)
{
	POP_FROM_STR(user_id);
	STR_POP_FROM_STR(user_cookie_code);

	IS_STR_ERR();
	return 0;
}

int jjboom::message_get_friends_groups::SerializeFromCString(char* c_str, size_t len)
{
	std::string str(c_str, len);
	return SerializeFromString(str);
}

ADD_MSG_ACHIEVE_HAVE_NAMESPACE(P_UINT64,user_id, message_get_friends_groups, jjboom)

ADD_MSG_STRING_ACHIEVE_HAVE_NAMESPACE(user_cookie_code, message_get_friends_groups, jjboom)

size_t jjboom::message_get_friends_groups_back::SerializeToString(std::string& str)
{
	size_t str_len = OVERALL_STR_LENGTH(other_name.size(), join_time.size());
	str.resize(str_len);

	ADD_TO_STR(other_id);
	ADD_TO_STR(back_type);
	STR_ADD_TO_STR(other_name);
	STR_ADD_TO_STR(join_time);

	_add_len = 0;
	return str_len;
}

char* jjboom::message_get_friends_groups_back::SerializeToCString(size_t& len)
{
	len = OVERALL_STR_LENGTH(other_name.size(), join_time.size());
	_c_data = new char[len];

	ADD_TO_CSTR(other_id);
	ADD_TO_CSTR(back_type);
	STR_ADD_TO_CSTR(other_name);
	STR_ADD_TO_CSTR(join_time);

	_add_len = 0;
	return _c_data;
}

int jjboom::message_get_friends_groups_back::SerializeFromString(std::string& str)
{
	POP_FROM_STR(other_id);
	POP_FROM_STR(back_type);
	STR_POP_FROM_STR(other_name);
	STR_POP_FROM_STR(join_time);

	IS_STR_ERR();
	return 0;
}

int jjboom::message_get_friends_groups_back::SerializeFromCString(char* c_str, size_t len)
{
	std::string str(c_str, len);
	return SerializeFromString(str);
}

ADD_MSG_ACHIEVE_HAVE_NAMESPACE(P_UINT64,other_id, message_get_friends_groups_back, jjboom)

ADD_MSG_ENUM_ACHIEVE_HAVE_NAMESPACE(TYPE, back_type, message_get_friends_groups_back, jjboom)

ADD_MSG_STRING_ACHIEVE_HAVE_NAMESPACE(other_name, message_get_friends_groups_back, jjboom)

ADD_MSG_STRING_ACHIEVE_HAVE_NAMESPACE(join_time, message_get_friends_groups_back, jjboom)

size_t jjboom::message_send_message::SerializeToString(std::string& str)
{
	size_t str_len = OVERALL_STR_LENGTH(user_cookie_code.size(), msg_body.size());
	str.resize(str_len);

	ADD_TO_STR(msg_type);
	ADD_TO_STR(user_id);
	STR_ADD_TO_STR(user_cookie_code);
	STR_ADD_TO_STR(msg_body);

	_add_len = 0;
	return str_len;
}

char* jjboom::message_send_message::SerializeToCString(size_t& len)
{
	len = OVERALL_STR_LENGTH(user_cookie_code.size(), msg_body.size());
	_c_data = new char[len];

	ADD_TO_CSTR(msg_type);
	ADD_TO_CSTR(user_id);
	STR_ADD_TO_CSTR(user_cookie_code);
	STR_ADD_TO_CSTR(msg_body);

	_add_len = 0;
	return _c_data;
}

int jjboom::message_send_message::SerializeFromString(std::string& str)
{
	POP_FROM_STR(msg_type);
	POP_FROM_STR(user_id);
	STR_POP_FROM_STR(user_cookie_code);
	STR_POP_FROM_STR(msg_body);

	IS_STR_ERR();
	return 0;
}

int jjboom::message_send_message::SerializeFromCString(char* c_str, size_t len)
{
	std::string str(c_str, len);
	return SerializeFromString(str);
}

ADD_MSG_ACHIEVE_HAVE_NAMESPACE(P_INT16,msg_type, message_send_message, jjboom)

ADD_MSG_ACHIEVE_HAVE_NAMESPACE(P_UINT64,user_id, message_send_message, jjboom)

ADD_MSG_STRING_ACHIEVE_HAVE_NAMESPACE(user_cookie_code, message_send_message, jjboom)

ADD_MSG_STRING_ACHIEVE_HAVE_NAMESPACE(msg_body, message_send_message, jjboom)

size_t jjboom::message_new_message::SerializeToString(std::string& str)
{
	size_t str_len = OVERALL_STR_LENGTH(other_name.size(), msg_body.size());
	str.resize(str_len);

	ADD_TO_STR(msg_type);
	ADD_TO_STR(group_id);
	ADD_TO_STR(other_id);
	STR_ADD_TO_STR(other_name);
	STR_ADD_TO_STR(msg_body);

	_add_len = 0;
	return str_len;
}

char* jjboom::message_new_message::SerializeToCString(size_t& len)
{
	len = OVERALL_STR_LENGTH(other_name.size(), msg_body.size());
	_c_data = new char[len];

	ADD_TO_CSTR(msg_type);
	ADD_TO_CSTR(group_id);
	ADD_TO_CSTR(other_id);
	STR_ADD_TO_CSTR(other_name);
	STR_ADD_TO_CSTR(msg_body);

	_add_len = 0;
	return _c_data;
}

int jjboom::message_new_message::SerializeFromString(std::string& str)
{
	POP_FROM_STR(msg_type);
	POP_FROM_STR(group_id);
	POP_FROM_STR(other_id);
	STR_POP_FROM_STR(other_name);
	STR_POP_FROM_STR(msg_body);

	IS_STR_ERR();
	return 0;
}

int jjboom::message_new_message::SerializeFromCString(char* c_str, size_t len)
{
	std::string str(c_str, len);
	return SerializeFromString(str);
}

ADD_MSG_ACHIEVE_HAVE_NAMESPACE(P_INT16,msg_type, message_new_message, jjboom)

ADD_MSG_ACHIEVE_HAVE_NAMESPACE(P_UINT64,group_id, message_new_message, jjboom)

ADD_MSG_ACHIEVE_HAVE_NAMESPACE(P_UINT64,other_id, message_new_message, jjboom)

ADD_MSG_STRING_ACHIEVE_HAVE_NAMESPACE(other_name, message_new_message, jjboom)

ADD_MSG_STRING_ACHIEVE_HAVE_NAMESPACE(msg_body, message_new_message, jjboom)


#ifndef _jjchat_msg_potato_h
#define _jjchat_msg_potato_h


#include "stink_potatobuf/stink_potatobuf.h"


namespace jjboom
{

class message_login final : public PotatoBuffer::_potatobuf
{
public:
	message_login() :
		user_id(0)
	{
		INIT_MSG_NUM(0,0,0,0,0,0,0,1,0,0,0,0,1);
	}

	~message_login(){}

	size_t SerializeToString(std::string& str) override;
	char* SerializeToCString(size_t& len) override;
	int SerializeFromString(std::string& str) override;
	int SerializeFromCString(char* c_str, size_t len) override;
	//user_id
	//None
	ADD_MSG(P_UINT64 ,user_id)

	//user_pwd
	//None
	ADD_MSG_STRING(user_pwd)

private:
	P_UINT64 user_id;
	std::string user_pwd;
}; // class message_login

class message_login_back final : public PotatoBuffer::_potatobuf
{
public:
	message_login_back() :
		is_success(false)
	{
		INIT_MSG_NUM(0,0,0,0,0,0,0,0,1,0,0,0,1);
	}

	~message_login_back(){}

	size_t SerializeToString(std::string& str) override;
	char* SerializeToCString(size_t& len) override;
	int SerializeFromString(std::string& str) override;
	int SerializeFromCString(char* c_str, size_t len) override;
	//is_success
	//None
	ADD_MSG(bool ,is_success)

	//cookie_code
	//None
	ADD_MSG_STRING(cookie_code)

private:
	bool is_success;
	std::string cookie_code;
}; // class message_login_back

class message_sign_up final : public PotatoBuffer::_potatobuf
{
public:
	message_sign_up()
	{
		INIT_MSG_NUM(0,0,0,0,0,0,0,0,0,0,0,0,3);
	}

	~message_sign_up(){}

	size_t SerializeToString(std::string& str) override;
	char* SerializeToCString(size_t& len) override;
	int SerializeFromString(std::string& str) override;
	int SerializeFromCString(char* c_str, size_t len) override;
	//user_name
	//None
	ADD_MSG_STRING(user_name)

	//user_pwd
	//None
	ADD_MSG_STRING(user_pwd)

	//salt
	//None
	ADD_MSG_STRING(salt)

private:
	std::string user_name;
	std::string user_pwd;
	std::string salt;
}; // class message_sign_up

class message_sign_up_back final : public PotatoBuffer::_potatobuf
{
public:
	message_sign_up_back() :
		sign_up_id(0),
		is_success(false)
	{
		INIT_MSG_NUM(0,0,0,0,0,0,0,1,1,0,0,0,1);
	}

	~message_sign_up_back(){}

	size_t SerializeToString(std::string& str) override;
	char* SerializeToCString(size_t& len) override;
	int SerializeFromString(std::string& str) override;
	int SerializeFromCString(char* c_str, size_t len) override;
	//sign_up_id
	//None
	ADD_MSG(P_UINT64 ,sign_up_id)

	//is_success
	//None
	ADD_MSG(bool ,is_success)

	//sign_up_time
	//None
	ADD_MSG_STRING(sign_up_time)

private:
	P_UINT64 sign_up_id;
	bool is_success;
	std::string sign_up_time;
}; // class message_sign_up_back

class message_get_sign_up_salt_back final : public PotatoBuffer::_potatobuf
{
public:
	message_get_sign_up_salt_back()
	{
		INIT_MSG_NUM(0,0,0,0,0,0,0,0,0,0,0,0,1);
	}

	~message_get_sign_up_salt_back(){}

	size_t SerializeToString(std::string& str) override;
	char* SerializeToCString(size_t& len) override;
	int SerializeFromString(std::string& str) override;
	int SerializeFromCString(char* c_str, size_t len) override;
	//salt
	//None
	ADD_MSG_STRING(salt)

private:
	std::string salt;
}; // class message_get_sign_up_salt_back

class message_get_sign_in_salt final : public PotatoBuffer::_potatobuf
{
public:
	message_get_sign_in_salt() :
		user_id(0)
	{
		INIT_MSG_NUM(0,0,0,0,0,0,0,1,0,0,0,0,0);
	}

	~message_get_sign_in_salt(){}

	size_t SerializeToString(std::string& str) override;
	char* SerializeToCString(size_t& len) override;
	int SerializeFromString(std::string& str) override;
	int SerializeFromCString(char* c_str, size_t len) override;
	//user_id
	//None
	ADD_MSG(P_UINT64 ,user_id)

private:
	P_UINT64 user_id;
}; // class message_get_sign_in_salt

class message_get_sign_in_salt_back final : public PotatoBuffer::_potatobuf
{
public:
	message_get_sign_in_salt_back()
	{
		INIT_MSG_NUM(0,0,0,0,0,0,0,0,0,0,0,0,1);
	}

	~message_get_sign_in_salt_back(){}

	size_t SerializeToString(std::string& str) override;
	char* SerializeToCString(size_t& len) override;
	int SerializeFromString(std::string& str) override;
	int SerializeFromCString(char* c_str, size_t len) override;
	//salt
	//None
	ADD_MSG_STRING(salt)

private:
	std::string salt;
}; // class message_get_sign_in_salt_back

class message_server_disconnect final : public PotatoBuffer::_potatobuf
{
public:
	message_server_disconnect()
	{
		INIT_MSG_NUM(0,0,0,0,0,0,0,0,0,0,0,0,1);
	}

	~message_server_disconnect(){}

	size_t SerializeToString(std::string& str) override;
	char* SerializeToCString(size_t& len) override;
	int SerializeFromString(std::string& str) override;
	int SerializeFromCString(char* c_str, size_t len) override;
	//reason
	//None
	ADD_MSG_STRING(reason)

private:
	std::string reason;
}; // class message_server_disconnect

class message_logout final : public PotatoBuffer::_potatobuf
{
public:
	message_logout() :
		user_id(0)
	{
		INIT_MSG_NUM(0,0,0,0,0,0,0,1,0,0,0,0,1);
	}

	~message_logout(){}

	size_t SerializeToString(std::string& str) override;
	char* SerializeToCString(size_t& len) override;
	int SerializeFromString(std::string& str) override;
	int SerializeFromCString(char* c_str, size_t len) override;
	//user_id
	//None
	ADD_MSG(P_UINT64 ,user_id)

	//user_cookie_code
	//None
	ADD_MSG_STRING(user_cookie_code)

private:
	P_UINT64 user_id;
	std::string user_cookie_code;
}; // class message_logout

class message_get_friends_groups final : public PotatoBuffer::_potatobuf
{
public:
	message_get_friends_groups() :
		user_id(0)
	{
		INIT_MSG_NUM(0,0,0,0,0,0,0,1,0,0,0,0,1);
	}

	~message_get_friends_groups(){}

	size_t SerializeToString(std::string& str) override;
	char* SerializeToCString(size_t& len) override;
	int SerializeFromString(std::string& str) override;
	int SerializeFromCString(char* c_str, size_t len) override;
	//user_id
	//None
	ADD_MSG(P_UINT64 ,user_id)

	//user_cookie_code
	//None
	ADD_MSG_STRING(user_cookie_code)

private:
	P_UINT64 user_id;
	std::string user_cookie_code;
}; // class message_get_friends_groups

class message_get_friends_groups_back final : public PotatoBuffer::_potatobuf
{
public:
	message_get_friends_groups_back() :
		other_id(0),
		back_type(TYPE(0))
	{
		INIT_MSG_NUM(0,0,0,0,0,0,0,1,0,0,0,1,2);
	}

	~message_get_friends_groups_back(){}

	size_t SerializeToString(std::string& str) override;
	char* SerializeToCString(size_t& len) override;
	int SerializeFromString(std::string& str) override;
	int SerializeFromCString(char* c_str, size_t len) override;

	//TYPE
	enum class TYPE : int {
		TYPE_FRIEND_ONLINE,
		TYPE_FRIEND_OFFLINE,
		TYPE_GROUP
	};

	//other_id
	//None
	ADD_MSG(P_UINT64 ,other_id)

	//back_type
	//None
	ADD_MSG_ENUM(TYPE, back_type)

	//other_name
	//None
	ADD_MSG_STRING(other_name)

	//join_time
	//None
	ADD_MSG_STRING(join_time)

private:
	P_UINT64 other_id;
	TYPE back_type;
	std::string other_name;
	std::string join_time;
}; // class message_get_friends_groups_back

class message_send_message final : public PotatoBuffer::_potatobuf
{
public:
	message_send_message() :
		msg_type(0),
		user_id(0)
	{
		INIT_MSG_NUM(0,1,0,0,0,0,0,1,0,0,0,0,2);
	}

	~message_send_message(){}

	size_t SerializeToString(std::string& str) override;
	char* SerializeToCString(size_t& len) override;
	int SerializeFromString(std::string& str) override;
	int SerializeFromCString(char* c_str, size_t len) override;
	//msg_type
	//None
	ADD_MSG(P_INT16 ,msg_type)

	//user_id
	//None
	ADD_MSG(P_UINT64 ,user_id)

	//user_cookie_code
	//None
	ADD_MSG_STRING(user_cookie_code)

	//msg_body
	//None
	ADD_MSG_STRING(msg_body)

private:
	P_INT16 msg_type;
	P_UINT64 user_id;
	std::string user_cookie_code;
	std::string msg_body;
}; // class message_send_message

class message_new_message final : public PotatoBuffer::_potatobuf
{
public:
	message_new_message() :
		msg_type(0),
		group_id(0),
		other_id(0)
	{
		INIT_MSG_NUM(0,1,0,0,0,0,0,2,0,0,0,0,2);
	}

	~message_new_message(){}

	size_t SerializeToString(std::string& str) override;
	char* SerializeToCString(size_t& len) override;
	int SerializeFromString(std::string& str) override;
	int SerializeFromCString(char* c_str, size_t len) override;
	//msg_type
	//None
	ADD_MSG(P_INT16 ,msg_type)

	//group_id
	//None
	ADD_MSG(P_UINT64 ,group_id)

	//other_id
	//None
	ADD_MSG(P_UINT64 ,other_id)

	//other_name
	//None
	ADD_MSG_STRING(other_name)

	//msg_body
	//None
	ADD_MSG_STRING(msg_body)

private:
	P_INT16 msg_type;
	P_UINT64 group_id;
	P_UINT64 other_id;
	std::string other_name;
	std::string msg_body;
}; // class message_new_message

} // namespace jjboom

#endif //jjchat_msg_potato_h

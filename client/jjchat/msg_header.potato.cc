#include "msg_header.potato.h"

size_t jjboom::message_header::SerializeToString(std::string& str)
{
	size_t str_len = OVERALL_STR_LENGTH();
	str.resize(str_len);

	ADD_TO_STR(body_size);
	ADD_TO_STR(msg_type);

	_add_len = 0;
	return str_len;
}

char* jjboom::message_header::SerializeToCString(size_t& len)
{
	len = OVERALL_STR_LENGTH();
	_c_data = new char[len];

	ADD_TO_CSTR(body_size);
	ADD_TO_CSTR(msg_type);

	_add_len = 0;
	return _c_data;
}

int jjboom::message_header::SerializeFromString(std::string& str)
{
	POP_FROM_STR(body_size);
	POP_FROM_STR(msg_type);

	IS_STR_ERR();
	return 0;
}

int jjboom::message_header::SerializeFromCString(char* c_str, size_t len)
{
	std::string str(c_str, len);
	return SerializeFromString(str);
}

ADD_MSG_ACHIEVE_HAVE_NAMESPACE(P_UINT64,body_size, message_header, jjboom)

ADD_MSG_ENUM_ACHIEVE_HAVE_NAMESPACE(MASSAGE_TYPE, msg_type, message_header, jjboom)


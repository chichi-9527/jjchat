#ifndef _msg_header_potato_h
#define _msg_header_potato_h


#include "stink_potatobuf/stink_potatobuf.h"


namespace jjboom
{

class message_header final : public PotatoBuffer::_potatobuf
{
public:
	message_header() :
		body_size(0),
		msg_type(MASSAGE_TYPE(0))
	{
		INIT_MSG_NUM(0,0,0,0,0,0,0,1,0,0,0,1,0);
	}

	~message_header(){}

	size_t SerializeToString(std::string& str) override;
	char* SerializeToCString(size_t& len) override;
	int SerializeFromString(std::string& str) override;
	int SerializeFromCString(char* c_str, size_t len) override;

	//MASSAGE_TYPE
	enum class MASSAGE_TYPE : int {
		MSG_LOGIN,
		MSG_LOGIN_BACK,
		MSG_GET_SIGN_IN_SALT,
		MSG_GET_SIGN_IN_SALT_BACK,
		MSG_SIGN_UP,
		MSG_SIGN_UP_BACK,
		MSG_GET_SIGN_UP_SALT,
		MSG_GET_SIGN_UP_SALT_BACK,
		MSG_LOGOUT,
		MSG_SERVER_DISCONNECT,
		MSG_SERVER_HEARTBEAT,
		MSG_GET_FRIENDS_GROUPS,
		MSG_GET_FRIENDS_GROUPS_BACK,
		MSG_NEW_MESSAGE,
		MSG_SEND_MESSAGE
	};

	//body_size
	//None
	ADD_MSG(P_UINT64 ,body_size)

	//msg_type
	//None
	ADD_MSG_ENUM(MASSAGE_TYPE, msg_type)

private:
	P_UINT64 body_size;
	MASSAGE_TYPE msg_type;
}; // class message_header

} // namespace jjboom

#endif //msg_header_potato_h

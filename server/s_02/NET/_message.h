#ifndef _MESSAGE
#define _MESSAGE

#include <iostream>
#include <vector>
#include <type_traits>
#include <cstring>



enum class Enum : unsigned int
{
	ServerAccept,
	ServerDeny,
	ServerPing,
	MessageAll,
	ServerMessage
};

namespace jjboom
{
	namespace message
	{
		template <typename T>
		struct _msg_header
		{
			T id{};
			//包体长度
			uint32_t size = 0;
		};

		template <typename T>
		struct _msg
		{
			_msg_header<T> _header{};
			std::vector<uint8_t> body;

			_msg()
			{
				_clear();
			}

			void _clear()
			{
				body.clear();
				_header.size = 0;
			}

			size_t size() const
			{
				return body.size();
			}

			void _set_header(_msg_header<T>* header)
			{
				_header.size = header->size;
				_header.id = header->id;
			}

			// Pushes any POD-like data into the message buffer
			template<typename DataType>
			friend _msg<T>& operator << (_msg<T>& msg, const DataType& data)
			{
				// Check that the type of the data being pushed is trivially copyable
				static_assert(std::is_standard_layout<DataType>::value, "Data is too complex to be pushed into vector");

				// Cache current size of vector, as this will be the point we insert the data
				size_t i = msg.body.size();

				// Resize the vector by the size of the data being pushed
				msg.body.resize(msg.body.size() + sizeof(DataType));

				// Physically copy the data into the newly allocated vector space
				std::memcpy(msg.body.data() + i, &data, sizeof(DataType));

				// Recalculate the message size
				msg._header.size = msg.size();

				// Return the target message so it can be "chained"
				return msg;
			}

			void append(const char* str, unsigned int len)
			{
				size_t i = body.size();
				body.resize(body.size() + len);
				std::memcpy(body.data() + i, str, len);
				_header.size = size();
			}

			// Pulls any POD-like data form the message buffer
			template<typename DataType>
			friend _msg<T>& operator >> (_msg<T>& msg, DataType& data)
			{
				// Check that the type of the data being pushed is trivially copyable
				static_assert(std::is_standard_layout<DataType>::value, "Data is too complex to be pulled from vector");

				// Cache the location towards the end of the vector where the pulled data starts
				size_t i = msg.body.size() - sizeof(DataType);

				// Physically copy the data from the vector into the user variable
				std::memcpy(&data, msg.body.data() + i, sizeof(DataType));

				// Shrink the vector to remove read bytes, and reset end position
				msg.body.resize(i);

				// Recalculate the message size
				msg._header.size = msg.size();

				// Return the target message so it can be "chained"
				return msg;
			}

			void popstr(char* str, unsigned int len)
			{
				size_t i = body.size() - len;
				std::memcpy(str, body.data() + i, len);
				body.resize(i);
				_header.size = size();
			}
		};
	}
}



#endif
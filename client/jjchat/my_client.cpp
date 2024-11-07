#include "my_client.h"

my_tcp_client::my_tcp_client()
{
    _deal_msg_pool.setMaxThreadCount(1);
}

my_tcp_client::~my_tcp_client()
{
}

void my_tcp_client::deal_msg_header()
{
    std::string header(_msg_header, _msg_header_size);
    jjboom::message_header msg_header;
    msg_header.SerializeFromString(header);

    if(msg_header.get_body_size() == 0)
    {
        switch (msg_header.get_msg_type()) {
        case jjboom::message_header::MASSAGE_TYPE::MSG_LOGIN_BACK:

            break;
        default:
            break;
        }
        _final_deal_msg();
        return;
    }

    std::string str_body;
    _read(msg_header.get_body_size(), str_body);

    switch (msg_header.get_msg_type()) {
    case jjboom::message_header::MASSAGE_TYPE::MSG_GET_SIGN_UP_SALT_BACK:
        _deal_msg_pool.start(new runnable_task(std::bind(&my_tcp_client::_do_GET_SIGN_UP_SALT_BACK, this, str_body)));
        break;
    case jjboom::message_header::MASSAGE_TYPE::MSG_SIGN_UP_BACK:
        _deal_msg_pool.start(new runnable_task(std::bind(&my_tcp_client::_do_SIGN_UP_BACK, this, str_body)));
        break;
    case jjboom::message_header::MASSAGE_TYPE::MSG_GET_SIGN_IN_SALT_BACK:
        _deal_msg_pool.start(new runnable_task(std::bind(&my_tcp_client::_do_GET_SIGN_IN_SALT_BACK, this, str_body)));
        break;
    case jjboom::message_header::MASSAGE_TYPE::MSG_LOGIN_BACK:
        _deal_msg_pool.start(new runnable_task(std::bind(&my_tcp_client::_do_LOGIN_BACK, this, str_body)));
        break;
    case jjboom::message_header::MASSAGE_TYPE::MSG_SERVER_DISCONNECT:
        _deal_msg_pool.start(new runnable_task(std::bind(&my_tcp_client::_do_SERVER_DISCONNECT, this, str_body)));
        break;
    case jjboom::message_header::MASSAGE_TYPE::MSG_GET_FRIENDS_GROUPS_BACK:
        _deal_msg_pool.start(new runnable_task(std::bind(&my_tcp_client::_do_GET_FRIENDS_GROUPS_BACK, this, str_body)));
        break;
    default:
        break;
    }
    _final_deal_msg();
}

void my_tcp_client::_do_GET_SIGN_UP_SALT_BACK(std::string str)
{
    jjboom::message_get_sign_up_salt_back get_sign_up_salt_back;
    if(get_sign_up_salt_back.SerializeFromString(str))
    {
        qDebug() << "get_sign_up_salt_back.SerializeFromString err";
        return;
    }
    QString salt(get_sign_up_salt_back.get_salt().c_str());
    emit SIGN_UP_SALT_BACK(salt);
}

void my_tcp_client::_do_SIGN_UP_BACK(std::string str)
{
    QString qstr_signup_back;
    jjboom::message_sign_up_back sign_up_back;
    if(sign_up_back.SerializeFromString(str))
    {
        // Serialize err
        qstr_signup_back = "数据错误";
        emit SIGN_UP_BACK(false, qstr_signup_back);
        return;
    }

    if(!sign_up_back.get_is_success())
    {
        // sign up err
        qstr_signup_back = "注册失败";
        emit SIGN_UP_BACK(false, qstr_signup_back);
        return;
    }

    qstr_signup_back = "注册成功";
    qstr_signup_back += " id 为" + QString::number((qulonglong)sign_up_back.get_sign_up_id()) + "; 时间 ：" + sign_up_back.get_sign_up_time().c_str();
    emit SIGN_UP_BACK(true, qstr_signup_back);
}

void my_tcp_client::_do_GET_SIGN_IN_SALT_BACK(std::string str)
{
    QString qstr_salt;
    jjboom::message_get_sign_in_salt_back get_sign_in_salt_back;
    if(get_sign_in_salt_back.SerializeFromString(str))
    {
        qstr_salt = "数据错误";
        emit GET_SIGN_IN_SALT_BACK(false, qstr_salt);
        return;
    }
    if(get_sign_in_salt_back.get_salt().size() == 0)
    {
        qstr_salt = "服务器错误或id错误";
        emit GET_SIGN_IN_SALT_BACK(false, qstr_salt);
        return;
    }
    qstr_salt = get_sign_in_salt_back.get_salt().c_str();
    emit GET_SIGN_IN_SALT_BACK(true, qstr_salt);
}

void my_tcp_client::_do_LOGIN_BACK(std::string str)
{
    jjboom::message_login_back login_back;
    if(login_back.SerializeFromString(str))
    {
        emit LOGIN_BACK(false, "数据错误");
        return;
    }
    QString cookie_code = login_back.get_cookie_code().c_str();
    emit LOGIN_BACK(login_back.get_is_success(), cookie_code);

}

void my_tcp_client::_do_SERVER_DISCONNECT(std::string str)
{
    jjboom::message_server_disconnect server_disconnect;
    QString reason("不明原因导致掉线");
    if(0 == server_disconnect.SerializeFromString(str))
    {
        reason = server_disconnect.get_reason().c_str();
    }
    emit SERVER_DISCONNECT(reason);
}

void my_tcp_client::_do_GET_FRIENDS_GROUPS_BACK(std::string str)
{
    // TO DO ....

}

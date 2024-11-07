#ifndef MY_CLIENT_H
#define MY_CLIENT_H

#include "tcp_client.h"

#include "msg_header.potato.h"
#include "jjchat_msg.potato.h"


class my_tcp_client final: public tcp_client
{
    Q_OBJECT
public:
    my_tcp_client();
    virtual ~my_tcp_client();

protected:
    virtual void deal_msg_header();

    void _do_GET_SIGN_UP_SALT_BACK(std::string str);
    void _do_SIGN_UP_BACK(std::string str);
    void _do_GET_SIGN_IN_SALT_BACK(std::string str);
    void _do_LOGIN_BACK(std::string str);
    void _do_SERVER_DISCONNECT(std::string str);
    void _do_GET_FRIENDS_GROUPS_BACK(std::string str);

signals:
    void SIGN_UP_SALT_BACK(QString);
    void SIGN_UP_BACK(bool, QString);
    void GET_SIGN_IN_SALT_BACK(bool, QString);
    void LOGIN_BACK(bool, QString);
    void SERVER_DISCONNECT(QString);

protected:
    QThreadPool _deal_msg_pool;
};

#endif // MY_CLIENT_H

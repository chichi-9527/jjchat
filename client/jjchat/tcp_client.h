#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QThreadPool>
#include <QString>
#include <QMutex>
#include <QMutexLocker>

#include <string>

#include "runnable_task.h"

class tcp_client : public QObject
{
    Q_OBJECT
public:
    tcp_client();
    virtual ~tcp_client();

    void start(size_t msg_header_size, QString ip, unsigned short port);
    void stop();

    int write(const char* header, size_t size_header, const char* body, size_t size_body);
    int write(const char* header, size_t size_header, const std::string& body);
    int write(const std::string& header, const char* body, size_t size_body);
    int write(const std::string& header, const std::string& body);

    size_t header_size();

protected:
    virtual void deal_msg_header() = 0;

    void _connect();
    void _connect_suc();
    void _connect_close();
    void _read_all();
    void _read_header();
    void _read(size_t read_size, char* buf);
    void _read(size_t read_size, std::string& buf);
    void _popstr_len(size_t len);
    void _send(const char *str, int len);
    void _final_deal_msg();

signals:
    void connect_close();

protected:

    size_t _msg_header_size;

    QThreadPool _read_header_pool;
    QThreadPool _send_pool;

    QByteArray _all_msg;
    QMutex _mutex;
    QString _ip;
    QTcpSocket* _socket;

    char* _msg_header;

    unsigned short _port;

    bool _is_connect;
};

#endif // TCP_CLIENT_H

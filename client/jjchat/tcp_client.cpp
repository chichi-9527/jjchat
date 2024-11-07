#include "tcp_client.h"

tcp_client::tcp_client()
    : QObject{nullptr},
    _msg_header_size(0),
    _port(0),
    _msg_header(nullptr),
    _socket(nullptr),
    _is_connect(false)
{}

tcp_client::~tcp_client()
{


    if(_msg_header)
    {
        delete[] _msg_header;
        _msg_header = nullptr;
    }
}

void tcp_client::start(size_t msg_header_size, QString ip, unsigned short port)
{
    _msg_header_size = msg_header_size;
    _msg_header = new char[msg_header_size];
    _ip = ip;
    _port = port;
    _connect();
}

void tcp_client::stop()
{
    _is_connect = false;
    _socket->close();
    _socket->deleteLater();
}

void tcp_client::_send(const char *str, int len)
{
    if(-1 == _socket->write(str, len))
    {
        _is_connect = false;
    }
}

void tcp_client::_final_deal_msg()
{
    _read_header_pool.start(new runnable_task(std::bind(&tcp_client::_read_header, this)));
}

int tcp_client::write(const char *header, size_t size_header, const char *body, size_t size_body)
{
    QMutexLocker locker(&_mutex);

    if(!_is_connect)
    {
        return -1;
    }
    // if not header
    if (nullptr == header || 0 == size_header)
    {
        return 0;
    }
    char* _write_header = new char[size_header];
    for (size_t i = 0; i < size_header; ++i)
    {
        _write_header[i] = header[i];
    }
    //_send_pool.start(new runnable_task(std::bind(&tcp_client::_send, this, _write_header, size_header)));
    _send(_write_header, size_header);
    // if not body
    if (nullptr == body || 0 == size_body)
    {
        return 0;
    }
    char* _write_str = new char[size_body];
    for (size_t i = 0; i < size_body; ++i)
    {
        _write_str[i] = body[i];
    }
    //_send_pool.start(new runnable_task(std::bind(&tcp_client::_send, this, _write_str, size_body)));
    _send(_write_str, size_body);
    return 0;
}

int tcp_client::write(const char *header, size_t size_header, const std::string &body)
{
    QMutexLocker locker(&_mutex);

    if(!_is_connect)
    {
        return -1;
    }
    // if not header
    if (nullptr == header || 0 == size_header)
    {
        return 0;
    }
    char* _write_header = new char[size_header];
    for (size_t i = 0; i < size_header; ++i)
    {
        _write_header[i] = header[i];
    }
    //_send_pool.start(new runnable_task(std::bind(&tcp_client::_send, this, _write_header, size_header)));
    _send(_write_header, size_header);
    size_t size_body = body.size();
    // if not body
    if (0 == size_body)
    {
        return 0;
    }
    char* _write_str = new char[size_body];
    for (size_t i = 0; i < size_body; ++i)
    {
        _write_str[i] = body[i];
    }
    //_send_pool.start(new runnable_task(std::bind(&tcp_client::_send, this, _write_str, size_body)));
    _send(_write_str, size_body);
    return 0;
}

int tcp_client::write(const std::string &header, const char *body, size_t size_body)
{
    QMutexLocker locker(&_mutex);

    if(!_is_connect)
    {
        return -1;
    }
    size_t size_header = header.size();
    // if not header
    if (0 == size_header)
    {
        return 0;
    }
    char* _write_header = new char[size_header];
    for (size_t i = 0; i < size_header; ++i)
    {
        _write_header[i] = header[i];
    }
    //_send_pool.start(new runnable_task(std::bind(&tcp_client::_send, this, _write_header, size_header)));
    _send(_write_header, size_header);
    // if not body
    if (nullptr == body || 0 == size_body)
    {
        return 0;
    }
    char* _write_str = new char[size_body];
    for (size_t i = 0; i < size_body; ++i)
    {
        _write_str[i] = body[i];
    }
    //_send_pool.start(new runnable_task(std::bind(&tcp_client::_send, this, _write_str, size_body)));
    _send(_write_str, size_body);
    return 0;
}

int tcp_client::write(const std::string &header, const std::string &body)
{
    QMutexLocker locker(&_mutex);

    if(!_is_connect)
    {
        return -1;
    }
    size_t size_header = header.size();
    // if not header
    if (0 == size_header)
    {
        return 0;
    }
    char* _write_header = new char[size_header];
    for (size_t i = 0; i < size_header; ++i)
    {
        _write_header[i] = header[i];
    }
    //_send_pool.start(new runnable_task(std::bind(&tcp_client::_send, this, _write_header, size_header)));
    _send(_write_header, size_header);
    size_t size_body = body.size();
    // if not body
    if (0 == size_body)
    {
        return 0;
    }
    char* _write_str = new char[size_body];
    for (size_t i = 0; i < size_body; ++i)
    {
        _write_str[i] = body[i];
    }
    //_send_pool.start(new runnable_task(std::bind(&tcp_client::_send, this, _write_str, size_body)));
    _send(_write_str, size_body);
    return 0;
}

size_t tcp_client::header_size()
{
    return _msg_header_size;
}

void tcp_client::_connect()
{
    _socket = new QTcpSocket(this);
    _socket->connectToHost(QHostAddress(_ip), _port);
    connect(_socket, &QTcpSocket::connected, this, &tcp_client::_connect_suc);
    connect(_socket, &QTcpSocket::disconnected, this, &tcp_client::_connect_close);
}

void tcp_client::_connect_suc()
{
    _is_connect = true;
    connect(_socket, &QTcpSocket::readyRead, this, &tcp_client::_read_all);
    _read_header_pool.start(new runnable_task(std::bind(&tcp_client::_read_header, this)));
}

void tcp_client::_connect_close()
{
    _is_connect = false;
    _all_msg.clear();

    emit connect_close();
}

void tcp_client::_read_all()
{
    QByteArray readarray = _socket->readAll();
    _mutex.lock();
    _all_msg += readarray;
    _mutex.unlock();
}

void tcp_client::_read_header()
{
    while(_is_connect)
    {
        if((size_t)_all_msg.size() < _msg_header_size)
        {
            continue;
        }
        for(size_t i = 0; i < _msg_header_size; ++i)
        {
            _msg_header[i] = _all_msg[i];
        }
        _popstr_len(_msg_header_size);
        break;
    }
    if(_is_connect)
    {
        deal_msg_header();
    }
}

void tcp_client::_read(size_t read_size, char *buf)
{
    while(_is_connect)
    {
        if((size_t)_all_msg.size() < read_size)
        {
            continue;
        }
        for(size_t i = 0; i < read_size; ++i)
        {
            buf[i] = _all_msg[i];
        }
        _popstr_len(read_size);
        break;
    }
}

void tcp_client::_read(size_t read_size, std::string &buf)
{
    buf.resize(read_size);
    while(_is_connect)
    {
        if((size_t)_all_msg.size() < read_size)
        {
            continue;
        }
        for(size_t i = 0; i < read_size; ++i)
        {
            buf[i] = _all_msg[i];
        }
        _popstr_len(read_size);
        break;
    }
}

void tcp_client::_popstr_len(size_t len)
{
    _mutex.lock();
    _all_msg = _all_msg.sliced(len);
    _mutex.unlock();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _tcp_client(nullptr)
    , _widget_login(nullptr)
    , _is_sign_in(false)
    , _my_id(0)
    , _connect_error(false)
    , _widget_myself(nullptr)
    , _widget_friends(nullptr)
{
    ui->setupUi(this);

    _tcp_client = new my_tcp_client();
    _tcp_client_connect_signals();

    _tcp_client->start(jjboom::message_header().buf_size_without_str(), QString("127.0.0.1"), 10240);

    _widget_login = new widget_login();
    connect(_widget_login, &widget_login::this_widget_close, this, &MainWindow::login_widget_close);
    connect(_widget_login, &widget_login::sign_in, this, &MainWindow::_post_sign_in_salt);
    connect(_widget_login, &widget_login::sign_up, this, &MainWindow::_post_sign_up_salt);
    _widget_login->show();

    widget_chat* chat1 = new widget_chat();
    chat1->show();

    _init_this_widget();
}

MainWindow::~MainWindow()
{
    delete ui;

    delete _widget_login;
}

void MainWindow::_str_md5(QByteArray &value, QString str)
{
    value = QCryptographicHash::hash(str.toLocal8Bit(), QCryptographicHash::Md5);
}

void MainWindow::_tcp_client_connect_signals()
{
    connect(_tcp_client, &my_tcp_client::connect_close, this, &MainWindow::_tcp_connect_close);
    connect(_tcp_client, &my_tcp_client::SIGN_UP_SALT_BACK, this, &MainWindow::_sign_up);
    connect(_tcp_client, &my_tcp_client::SIGN_UP_BACK, this, &MainWindow::_sign_up_back);
    connect(_tcp_client, &my_tcp_client::GET_SIGN_IN_SALT_BACK, this, &MainWindow::_sign_in);
    connect(_tcp_client, &my_tcp_client::LOGIN_BACK, this, &MainWindow::_login_back);
}

void MainWindow::_login_success()
{
    _widget_login->clear_widget();
    _widget_login->hide();

    _get_friends();

    this->show();
}

void MainWindow::_init_this_widget()
{
    _widget_myself = new widget_myself(this);
    _widget_friends = new widget_friends(this);
    ui->verticalLayout->addWidget(_widget_myself);
    ui->verticalLayout->addWidget(_widget_friends);
}

void MainWindow::_get_friends()
{
    jjboom::message_get_friends_groups get_friends_groups;
    get_friends_groups.set_user_id(_my_id);
    get_friends_groups.set_user_cookie_code(_cookie_code.toStdString());
    jjboom::message_header header;
    header.set_msg_type(jjboom::message_header::MASSAGE_TYPE::MSG_GET_FRIENDS_GROUPS);
    std::string str_get_friends_groups;
    header.set_body_size(get_friends_groups.SerializeToString(str_get_friends_groups));
    std::string str_header;
    header.SerializeToString(str_header);

    _tcp_client->write(str_header, str_get_friends_groups);
}

void MainWindow::login_widget_close()
{
    this->close();
}

void MainWindow::_tcp_connect_close()
{
    qDebug() << "断开连接";
}

void MainWindow::_sign_in(bool data_ok, QString salt)
{
    qDebug() << salt;
    if(!data_ok)
    {
        _widget_login->set_lable_signin_back("服务器错误");
        _my_id = 0;
        _pwd.clear();
        return;
    }

    QByteArray value;
    _str_md5(value, _pwd + salt);

    std::string str_header;
    std::string str_login;

    jjboom::message_login login;
    login.set_user_id(_my_id);
    login.set_user_pwd(value.toStdString());
    jjboom::message_header header;
    header.set_msg_type(jjboom::message_header::MASSAGE_TYPE::MSG_LOGIN);
    header.set_body_size(login.SerializeToString(str_login));
    header.SerializeToString(str_header);

    _tcp_client->write(str_header, str_login);
    _pwd.clear();
}

void MainWindow::_post_sign_in_salt(unsigned long long id, QString pwd)
{
    _pwd = pwd;
    _my_id = id;

    jjboom::message_get_sign_in_salt get_sign_in_salt;
    jjboom::message_header header;
    get_sign_in_salt.set_user_id(id);
    std::string str_get_sign_in_salt;
    header.set_msg_type(jjboom::message_header::MASSAGE_TYPE::MSG_GET_SIGN_IN_SALT);
    header.set_body_size(get_sign_in_salt.SerializeToString(str_get_sign_in_salt));
    std::string str_header;
    header.SerializeToString(str_header);

    _tcp_client->write(str_header, str_get_sign_in_salt);
}

void MainWindow::_post_sign_up_salt(QString pwd, QString name)
{
    _pwd = pwd;
    _name = name;

    jjboom::message_header header;
    header.set_body_size(0);
    header.set_msg_type(jjboom::message_header::MASSAGE_TYPE::MSG_GET_SIGN_UP_SALT);
    std::string str_header;
    header.SerializeToString(str_header);
    _tcp_client->write(str_header, nullptr, 0);

}

void MainWindow::_sign_up(QString salt)
{
    QByteArray value;
    _str_md5(value, _pwd + salt);

    jjboom::message_sign_up sign_up;
    sign_up.set_user_name(_name.toStdString());
    sign_up.set_user_pwd(value.toStdString());
    sign_up.set_salt(salt.toStdString());
    std::string str_sign_up;

    jjboom::message_header header;
    header.set_body_size(sign_up.SerializeToString(str_sign_up));
    header.set_msg_type(jjboom::message_header::MASSAGE_TYPE::MSG_SIGN_UP);
    std::string str_header;
    header.SerializeToString(str_header);

    _tcp_client->write(str_header, str_sign_up);
}

void MainWindow::_sign_up_back(bool is_success, QString qstr)
{
    _widget_login->set_lable_signup_back(qstr);
    if(!is_success)
    {
        _widget_login->set_lable_signup_back("sign up error");
    }
    _pwd.clear();
}

void MainWindow::_login_back(bool is_success, QString cookie_code)
{
    if(!is_success)
    {
        _widget_login->set_lable_signin_back(cookie_code);
        return;
    }
    // login success
    _login_success();
}

void MainWindow::_server_disconnect(QString reason)
{
    // 服务器端主动断开连接
}


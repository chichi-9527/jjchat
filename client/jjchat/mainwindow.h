#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QByteArray>
#include <QString>
#include <QCryptographicHash>

#include "my_client.h"
#include "widget_login.h"
#include "widget_chat.h"
#include "widget_myself.h"
#include "widget_friends.h"

#include "jjchat_msg.potato.h"

#include <QDebug>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void _str_md5(QByteArray& value, QString str);
    void _tcp_client_connect_signals();

    void _login_success();
    void _init_this_widget();
    void _get_friends();

private slots:
    void login_widget_close();
    void _tcp_connect_close();
    void _sign_in(bool data_ok, QString salt);
    void _post_sign_in_salt(unsigned long long id, QString pwd);
    void _post_sign_up_salt(QString pwd, QString name);
    void _sign_up(QString salt);
    void _sign_up_back(bool is_success, QString qstr);
    void _login_back(bool is_success, QString cookie_code);
    void _server_disconnect(QString reason);

private:
    QString _pwd;
    QString _name;
    QString _cookie_code;

    unsigned long long _my_id;

    Ui::MainWindow *ui;

    my_tcp_client* _tcp_client;
    widget_login* _widget_login;
    widget_myself* _widget_myself;
    widget_friends* _widget_friends;

    bool _is_sign_in;
    bool _connect_error;

};
#endif // MAINWINDOW_H

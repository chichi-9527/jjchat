#ifndef WIDGET_LOGIN_H
#define WIDGET_LOGIN_H

#include <QWidget>
#include <QRegularExpressionValidator>

namespace Ui {
class widget_login;
}

class widget_login : public QWidget
{
    Q_OBJECT

public:
    explicit widget_login(QWidget *parent = nullptr);
    ~widget_login();

    void set_lable_signin_back(QString value);
    void set_lable_signup_back(QString value);
    void clear_widget();

    void closeEvent(QCloseEvent* e) override;

signals:
    void sign_in(unsigned long long, QString);
    void sign_up(QString, QString);
    void this_widget_close();

private slots:
    void on_pushButton_signin_clicked();

    void on_pushButton_to_signup_clicked();

    void on_pushButton_to_signin_clicked();

    void on_pushButton_signup_clicked();

private:
    Ui::widget_login *ui;
};

#endif // WIDGET_LOGIN_H

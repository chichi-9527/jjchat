#include "widget_login.h"
#include "ui_widget_login.h"

widget_login::widget_login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::widget_login)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_QuitOnClose, false);

    ui->label_signin_back->hide();
    ui->label_signup_back->hide();
    this->setWindowTitle("sign in");
    ui->lineEdit_sigin_id->setValidator(new QRegularExpressionValidator(QRegularExpression("[1-9][0-9]+$")));
    ui->lineEdit_sigin_id->setMaxLength(20);

}

widget_login::~widget_login()
{
    delete ui;

}

void widget_login::set_lable_signin_back(QString value)
{
    ui->label_signin_back->setText(value);
    ui->label_signin_back->show();
    ui->pushButton_signin->setDisabled(false);
}

void widget_login::set_lable_signup_back(QString value)
{
    ui->label_signup_back->setText(value);
    ui->label_signup_back->show();
    ui->pushButton_signup->setDisabled(false);
}

void widget_login::clear_widget()
{
    ui->label_signin_back->hide();
    ui->label_signup_back->hide();
    ui->pushButton_signin->setDisabled(false);
    ui->pushButton_signup->setDisabled(false);
}

void widget_login::closeEvent(QCloseEvent *e)
{
    emit this_widget_close();
}


void widget_login::on_pushButton_signin_clicked()
{
    ui->label_signin_back->hide();
    ui->pushButton_signin->setDisabled(true);
    bool ok;
    qulonglong id = ui->lineEdit_sigin_id->text().toULongLong(&ok);
    if(!ok)
    {
        ui->label_signin_back->setText("id error");
        ui->label_signin_back->show();
        ui->pushButton_signin->setDisabled(false);
        return;
    }

    QString pwd = ui->lineEdit_sigin_pwd->text();
    ui->label_signin_back->setText("正在登录...");
    ui->label_signin_back->show();
    emit sign_in(id, pwd);
}


void widget_login::on_pushButton_to_signup_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_2);
    this->setWindowTitle("sign up");
}


void widget_login::on_pushButton_to_signin_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page);
    this->setWindowTitle("sign in");
}


void widget_login::on_pushButton_signup_clicked()
{
    ui->pushButton_signup->setDisabled(true);
    ui->label_signup_back->hide();
    QString pwd1 = ui->lineEdit_signup_pwd1->text();
    QString pwd2 = ui->lineEdit_signup_pwd2->text();
    if(pwd1.size() == 0 || !(pwd1 == pwd2))
    {
        ui->label_signup_back->setText("密码不符合规范");
        ui->label_signup_back->show();
        ui->pushButton_signup->setDisabled(false);
        return;
    }
    if(pwd1.size() > 29)
    {
        ui->label_signup_back->setText("密码不能超过28个字节");
        ui->label_signup_back->show();
        ui->pushButton_signup->setDisabled(false);
        return;
    }
    QString name = ui->lineEdit_sign_up_name->text();
    if(name.size() == 0)
    {
        ui->label_signup_back->setText("用户名不能为空");
        ui->label_signup_back->show();
        ui->pushButton_signup->setDisabled(false);
        return;
    }
    if(name.size() > 29)
    {
        ui->label_signup_back->setText("用户名不能超过28个字节");
        ui->label_signup_back->show();
        ui->pushButton_signup->setDisabled(false);
        return;
    }
    ui->label_signup_back->setText("正在注册...");
    ui->label_signup_back->show();
    emit sign_up(pwd1, name);
}


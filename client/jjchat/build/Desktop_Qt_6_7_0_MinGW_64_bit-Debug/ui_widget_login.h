/********************************************************************************
** Form generated from reading UI file 'widget_login.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_LOGIN_H
#define UI_WIDGET_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget_login
{
public:
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_sigin_id;
    QLineEdit *lineEdit_sigin_pwd;
    QLabel *label_signin_back;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_signin;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_to_signup;
    QWidget *page_2;
    QLabel *label_3;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit_sign_up_name;
    QLineEdit *lineEdit_signup_pwd1;
    QLineEdit *lineEdit_signup_pwd2;
    QLabel *label_signup_back;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_signup;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_to_signin;

    void setupUi(QWidget *widget_login)
    {
        if (widget_login->objectName().isEmpty())
            widget_login->setObjectName("widget_login");
        widget_login->resize(400, 300);
        widget_login->setMinimumSize(QSize(400, 300));
        widget_login->setMaximumSize(QSize(400, 300));
        widget_login->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        gridLayout = new QGridLayout(widget_login);
        gridLayout->setObjectName("gridLayout");
        stackedWidget = new QStackedWidget(widget_login);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 0, 81, 41));
        label->setStyleSheet(QString::fromUtf8("font: 87 20pt \"Arial Black\";"));
        verticalLayoutWidget = new QWidget(page);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(20, 60, 331, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_sigin_id = new QLineEdit(verticalLayoutWidget);
        lineEdit_sigin_id->setObjectName("lineEdit_sigin_id");
        lineEdit_sigin_id->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;border-radius:\n"
"7px;padding:2px 4px;\n"
"font: 10pt \"Candara\";"));

        verticalLayout->addWidget(lineEdit_sigin_id);

        lineEdit_sigin_pwd = new QLineEdit(verticalLayoutWidget);
        lineEdit_sigin_pwd->setObjectName("lineEdit_sigin_pwd");
        lineEdit_sigin_pwd->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;border-radius:\n"
"7px;padding:2px 4px;\n"
"font: 10pt \"Candara\";"));
        lineEdit_sigin_pwd->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout->addWidget(lineEdit_sigin_pwd);

        label_signin_back = new QLabel(page);
        label_signin_back->setObjectName("label_signin_back");
        label_signin_back->setGeometry(QRect(20, 150, 331, 31));
        horizontalLayoutWidget = new QWidget(page);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(20, 200, 331, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_signin = new QPushButton(horizontalLayoutWidget);
        pushButton_signin->setObjectName("pushButton_signin");
        pushButton_signin->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    color:#ffffff; /*\346\226\207\345\255\227\351\242\234\350\211\262*/\n"
"    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #aa55ff, stop: 1 #1296db);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:outset; /*\350\276\271\346\241\206\351\243\216\346\240\274*/\n"
"    border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"    border-color:#0055ff; /*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    border-radius:10px; /*\350\276\271\346\241\206\345\200\222\350\247\222*/\n"
"    font:bold 14px; /*\345\255\227\344\275\223*/\n"
"    font-family: Segoe UI;\n"
"    min-width:100px;/*\346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    min-height:20px;/*\346\216\247\344\273\266\346\234\200\345\260\217\351\253\230\345\272\246*/\n"
"    padding:4px;/*\345\206\205\350\276\271\350\267\235*/\n"
"}\n"
" \n"
"QPushButton:hover\n"
"{\n"
"    color:#ffffff; /*\346\226\207\345\255\227\351\242\234\350\211\262*/\n"
""
                        "    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #ff55ff, stop: 1 #1296db);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:outset; /*\350\276\271\346\241\206\351\243\216\346\240\274*/\n"
"    border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"    border-color:#0055ff; /*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    border-radius:10px; /*\350\276\271\346\241\206\345\200\222\350\247\222*/\n"
"    font:bold 14px; /*\345\255\227\344\275\223*/\n"
"    font-family: Segoe UI;\n"
"    min-width:100px;/*\346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    min-height:20px;/*\346\216\247\344\273\266\346\234\200\345\260\217\351\253\230\345\272\246*/\n"
"    padding:4px;/*\345\206\205\350\276\271\350\267\235*/\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    color:#ffffff; /*\346\226\207\345\255\227\351\242\234\350\211\262*/\n"
"    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #ff55ff, stop: 1 #aa00ff);/"
                        "*\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:outset; /*\350\276\271\346\241\206\351\243\216\346\240\274*/\n"
"    border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"    border-color:#0055ff; /*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    border-radius:10px; /*\350\276\271\346\241\206\345\200\222\350\247\222*/\n"
"    font:bold 14px; /*\345\255\227\344\275\223*/\n"
"    font-family: Segoe UI;\n"
"    min-width:100px;/*\346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    min-height:20px;/*\346\216\247\344\273\266\346\234\200\345\260\217\351\253\230\345\272\246*/\n"
"    padding:4px;/*\345\206\205\350\276\271\350\267\235*/\n"
"}"));

        horizontalLayout->addWidget(pushButton_signin);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_to_signup = new QPushButton(horizontalLayoutWidget);
        pushButton_to_signup->setObjectName("pushButton_to_signup");
        pushButton_to_signup->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    color:#ffffff; /*\346\226\207\345\255\227\351\242\234\350\211\262*/\n"
"    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #aa55ff, stop: 1 #1296db);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:outset; /*\350\276\271\346\241\206\351\243\216\346\240\274*/\n"
"    border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"    border-color:#0055ff; /*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    border-radius:10px; /*\350\276\271\346\241\206\345\200\222\350\247\222*/\n"
"    font:bold 14px; /*\345\255\227\344\275\223*/\n"
"    font-family: Segoe UI;\n"
"    min-width:100px;/*\346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    min-height:20px;/*\346\216\247\344\273\266\346\234\200\345\260\217\351\253\230\345\272\246*/\n"
"    padding:4px;/*\345\206\205\350\276\271\350\267\235*/\n"
"}\n"
" \n"
"QPushButton:hover\n"
"{\n"
"    color:#ffffff; /*\346\226\207\345\255\227\351\242\234\350\211\262*/\n"
""
                        "    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #ff55ff, stop: 1 #1296db);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:outset; /*\350\276\271\346\241\206\351\243\216\346\240\274*/\n"
"    border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"    border-color:#0055ff; /*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    border-radius:10px; /*\350\276\271\346\241\206\345\200\222\350\247\222*/\n"
"    font:bold 14px; /*\345\255\227\344\275\223*/\n"
"    font-family: Segoe UI;\n"
"    min-width:100px;/*\346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    min-height:20px;/*\346\216\247\344\273\266\346\234\200\345\260\217\351\253\230\345\272\246*/\n"
"    padding:4px;/*\345\206\205\350\276\271\350\267\235*/\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    color:#ffffff; /*\346\226\207\345\255\227\351\242\234\350\211\262*/\n"
"    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #ff55ff, stop: 1 #aa00ff);/"
                        "*\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:outset; /*\350\276\271\346\241\206\351\243\216\346\240\274*/\n"
"    border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"    border-color:#0055ff; /*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    border-radius:10px; /*\350\276\271\346\241\206\345\200\222\350\247\222*/\n"
"    font:bold 14px; /*\345\255\227\344\275\223*/\n"
"    font-family: Segoe UI;\n"
"    min-width:100px;/*\346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    min-height:20px;/*\346\216\247\344\273\266\346\234\200\345\260\217\351\253\230\345\272\246*/\n"
"    padding:4px;/*\345\206\205\350\276\271\350\267\235*/\n"
"}"));

        horizontalLayout->addWidget(pushButton_to_signup);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label_3 = new QLabel(page_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 0, 81, 41));
        label_3->setStyleSheet(QString::fromUtf8("font: 87 20pt \"Arial Black\";"));
        verticalLayoutWidget_2 = new QWidget(page_2);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(10, 52, 351, 101));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lineEdit_sign_up_name = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_sign_up_name->setObjectName("lineEdit_sign_up_name");
        lineEdit_sign_up_name->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;border-radius:\n"
"7px;padding:2px 4px;\n"
"font: 10pt \"Candara\";"));

        verticalLayout_2->addWidget(lineEdit_sign_up_name);

        lineEdit_signup_pwd1 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_signup_pwd1->setObjectName("lineEdit_signup_pwd1");
        lineEdit_signup_pwd1->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;border-radius:\n"
"7px;padding:2px 4px;\n"
"font: 10pt \"Candara\";"));
        lineEdit_signup_pwd1->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_2->addWidget(lineEdit_signup_pwd1);

        lineEdit_signup_pwd2 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_signup_pwd2->setObjectName("lineEdit_signup_pwd2");
        lineEdit_signup_pwd2->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
"border:1px groove gray;border-radius:\n"
"7px;padding:2px 4px;\n"
"font: 10pt \"Candara\";"));
        lineEdit_signup_pwd2->setEchoMode(QLineEdit::EchoMode::Password);

        verticalLayout_2->addWidget(lineEdit_signup_pwd2);

        label_signup_back = new QLabel(page_2);
        label_signup_back->setObjectName("label_signup_back");
        label_signup_back->setGeometry(QRect(10, 160, 351, 21));
        horizontalLayoutWidget_2 = new QWidget(page_2);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(10, 190, 351, 80));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_signup = new QPushButton(horizontalLayoutWidget_2);
        pushButton_signup->setObjectName("pushButton_signup");
        pushButton_signup->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    color:#ffffff; /*\346\226\207\345\255\227\351\242\234\350\211\262*/\n"
"    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #aa55ff, stop: 1 #1296db);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:outset; /*\350\276\271\346\241\206\351\243\216\346\240\274*/\n"
"    border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"    border-color:#0055ff; /*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    border-radius:10px; /*\350\276\271\346\241\206\345\200\222\350\247\222*/\n"
"    font:bold 14px; /*\345\255\227\344\275\223*/\n"
"    font-family: Segoe UI;\n"
"    min-width:100px;/*\346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    min-height:20px;/*\346\216\247\344\273\266\346\234\200\345\260\217\351\253\230\345\272\246*/\n"
"    padding:4px;/*\345\206\205\350\276\271\350\267\235*/\n"
"}\n"
" \n"
"QPushButton:hover\n"
"{\n"
"    color:#ffffff; /*\346\226\207\345\255\227\351\242\234\350\211\262*/\n"
""
                        "    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #ff55ff, stop: 1 #1296db);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:outset; /*\350\276\271\346\241\206\351\243\216\346\240\274*/\n"
"    border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"    border-color:#0055ff; /*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    border-radius:10px; /*\350\276\271\346\241\206\345\200\222\350\247\222*/\n"
"    font:bold 14px; /*\345\255\227\344\275\223*/\n"
"    font-family: Segoe UI;\n"
"    min-width:100px;/*\346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    min-height:20px;/*\346\216\247\344\273\266\346\234\200\345\260\217\351\253\230\345\272\246*/\n"
"    padding:4px;/*\345\206\205\350\276\271\350\267\235*/\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    color:#ffffff; /*\346\226\207\345\255\227\351\242\234\350\211\262*/\n"
"    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #ff55ff, stop: 1 #aa00ff);/"
                        "*\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:outset; /*\350\276\271\346\241\206\351\243\216\346\240\274*/\n"
"    border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"    border-color:#0055ff; /*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    border-radius:10px; /*\350\276\271\346\241\206\345\200\222\350\247\222*/\n"
"    font:bold 14px; /*\345\255\227\344\275\223*/\n"
"    font-family: Segoe UI;\n"
"    min-width:100px;/*\346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    min-height:20px;/*\346\216\247\344\273\266\346\234\200\345\260\217\351\253\230\345\272\246*/\n"
"    padding:4px;/*\345\206\205\350\276\271\350\267\235*/\n"
"}"));

        horizontalLayout_2->addWidget(pushButton_signup);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_to_signin = new QPushButton(horizontalLayoutWidget_2);
        pushButton_to_signin->setObjectName("pushButton_to_signin");
        pushButton_to_signin->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"    color:#ffffff; /*\346\226\207\345\255\227\351\242\234\350\211\262*/\n"
"    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #aa55ff, stop: 1 #1296db);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:outset; /*\350\276\271\346\241\206\351\243\216\346\240\274*/\n"
"    border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"    border-color:#0055ff; /*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    border-radius:10px; /*\350\276\271\346\241\206\345\200\222\350\247\222*/\n"
"    font:bold 14px; /*\345\255\227\344\275\223*/\n"
"    font-family: Segoe UI;\n"
"    min-width:100px;/*\346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    min-height:20px;/*\346\216\247\344\273\266\346\234\200\345\260\217\351\253\230\345\272\246*/\n"
"    padding:4px;/*\345\206\205\350\276\271\350\267\235*/\n"
"}\n"
" \n"
"QPushButton:hover\n"
"{\n"
"    color:#ffffff; /*\346\226\207\345\255\227\351\242\234\350\211\262*/\n"
""
                        "    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #ff55ff, stop: 1 #1296db);/*\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:outset; /*\350\276\271\346\241\206\351\243\216\346\240\274*/\n"
"    border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"    border-color:#0055ff; /*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    border-radius:10px; /*\350\276\271\346\241\206\345\200\222\350\247\222*/\n"
"    font:bold 14px; /*\345\255\227\344\275\223*/\n"
"    font-family: Segoe UI;\n"
"    min-width:100px;/*\346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    min-height:20px;/*\346\216\247\344\273\266\346\234\200\345\260\217\351\253\230\345\272\246*/\n"
"    padding:4px;/*\345\206\205\350\276\271\350\267\235*/\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    color:#ffffff; /*\346\226\207\345\255\227\351\242\234\350\211\262*/\n"
"    background-color:qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop:0 #ff55ff, stop: 1 #aa00ff);/"
                        "*\350\203\214\346\231\257\350\211\262*/\n"
"    border-style:outset; /*\350\276\271\346\241\206\351\243\216\346\240\274*/\n"
"    border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"    border-color:#0055ff; /*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"    border-radius:10px; /*\350\276\271\346\241\206\345\200\222\350\247\222*/\n"
"    font:bold 14px; /*\345\255\227\344\275\223*/\n"
"    font-family: Segoe UI;\n"
"    min-width:100px;/*\346\216\247\344\273\266\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    min-height:20px;/*\346\216\247\344\273\266\346\234\200\345\260\217\351\253\230\345\272\246*/\n"
"    padding:4px;/*\345\206\205\350\276\271\350\267\235*/\n"
"}"));

        horizontalLayout_2->addWidget(pushButton_to_signin);

        stackedWidget->addWidget(page_2);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);


        retranslateUi(widget_login);

        QMetaObject::connectSlotsByName(widget_login);
    } // setupUi

    void retranslateUi(QWidget *widget_login)
    {
        widget_login->setWindowTitle(QCoreApplication::translate("widget_login", "Form", nullptr));
        label->setText(QCoreApplication::translate("widget_login", "\347\231\273\345\275\225", nullptr));
        lineEdit_sigin_id->setPlaceholderText(QCoreApplication::translate("widget_login", "input id", nullptr));
        lineEdit_sigin_pwd->setPlaceholderText(QCoreApplication::translate("widget_login", "input password", nullptr));
        label_signin_back->setText(QCoreApplication::translate("widget_login", "TextLabel", nullptr));
        pushButton_signin->setText(QCoreApplication::translate("widget_login", "\347\231\273\345\275\225", nullptr));
        pushButton_to_signup->setText(QCoreApplication::translate("widget_login", "\345\216\273\346\263\250\345\206\214", nullptr));
        label_3->setText(QCoreApplication::translate("widget_login", "\346\263\250\345\206\214", nullptr));
        lineEdit_sign_up_name->setPlaceholderText(QCoreApplication::translate("widget_login", "name", nullptr));
        lineEdit_signup_pwd1->setPlaceholderText(QCoreApplication::translate("widget_login", "input password", nullptr));
        lineEdit_signup_pwd2->setPlaceholderText(QCoreApplication::translate("widget_login", "input password again", nullptr));
        label_signup_back->setText(QCoreApplication::translate("widget_login", "TextLabel", nullptr));
        pushButton_signup->setText(QCoreApplication::translate("widget_login", "\346\263\250\345\206\214", nullptr));
        pushButton_to_signin->setText(QCoreApplication::translate("widget_login", "\345\216\273\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widget_login: public Ui_widget_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_LOGIN_H

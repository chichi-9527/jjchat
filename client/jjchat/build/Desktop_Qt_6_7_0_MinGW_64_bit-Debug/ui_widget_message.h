/********************************************************************************
** Form generated from reading UI file 'widget_message.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_MESSAGE_H
#define UI_WIDGET_MESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget_message
{
public:
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page_left;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_page_left_img;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label_page_left_name_time;
    QTextEdit *textEdit_page_left;
    QWidget *page_right;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_page_right_name_time;
    QTextEdit *textEdit_page_right;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_page_right_img;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *widget_message)
    {
        if (widget_message->objectName().isEmpty())
            widget_message->setObjectName("widget_message");
        widget_message->resize(604, 129);
        widget_message->setMinimumSize(QSize(0, 0));
        widget_message->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        gridLayout = new QGridLayout(widget_message);
        gridLayout->setObjectName("gridLayout");
        stackedWidget = new QStackedWidget(widget_message);
        stackedWidget->setObjectName("stackedWidget");
        page_left = new QWidget();
        page_left->setObjectName("page_left");
        horizontalLayout = new QHBoxLayout(page_left);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_page_left_img = new QLabel(page_left);
        label_page_left_img->setObjectName("label_page_left_img");
        label_page_left_img->setMinimumSize(QSize(50, 50));

        verticalLayout_2->addWidget(label_page_left_img);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_page_left_name_time = new QLabel(page_left);
        label_page_left_name_time->setObjectName("label_page_left_name_time");

        verticalLayout->addWidget(label_page_left_name_time);

        textEdit_page_left = new QTextEdit(page_left);
        textEdit_page_left->setObjectName("textEdit_page_left");
        textEdit_page_left->setFrameShape(QFrame::Shape::NoFrame);
        textEdit_page_left->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        textEdit_page_left->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);

        verticalLayout->addWidget(textEdit_page_left);


        horizontalLayout->addLayout(verticalLayout);

        stackedWidget->addWidget(page_left);
        page_right = new QWidget();
        page_right->setObjectName("page_right");
        horizontalLayout_3 = new QHBoxLayout(page_right);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_page_right_name_time = new QLabel(page_right);
        label_page_right_name_time->setObjectName("label_page_right_name_time");

        horizontalLayout_2->addWidget(label_page_right_name_time);


        verticalLayout_4->addLayout(horizontalLayout_2);

        textEdit_page_right = new QTextEdit(page_right);
        textEdit_page_right->setObjectName("textEdit_page_right");
        textEdit_page_right->setStyleSheet(QString::fromUtf8("font: 14pt \"\345\256\213\344\275\223\";\n"
"border-radius:15px;\n"
"background-color: rgb(13, 170, 83);"));
        textEdit_page_right->setFrameShape(QFrame::Shape::NoFrame);
        textEdit_page_right->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        textEdit_page_right->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);

        verticalLayout_4->addWidget(textEdit_page_right);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_page_right_img = new QLabel(page_right);
        label_page_right_img->setObjectName("label_page_right_img");
        label_page_right_img->setMinimumSize(QSize(50, 50));

        verticalLayout_3->addWidget(label_page_right_img);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout_3->addLayout(verticalLayout_3);

        stackedWidget->addWidget(page_right);

        gridLayout->addWidget(stackedWidget, 1, 0, 1, 1);


        retranslateUi(widget_message);

        QMetaObject::connectSlotsByName(widget_message);
    } // setupUi

    void retranslateUi(QWidget *widget_message)
    {
        widget_message->setWindowTitle(QCoreApplication::translate("widget_message", "Form", nullptr));
        label_page_left_img->setText(QCoreApplication::translate("widget_message", "TextLabel", nullptr));
        label_page_left_name_time->setText(QCoreApplication::translate("widget_message", "TextLabel", nullptr));
        textEdit_page_left->setHtml(QCoreApplication::translate("widget_message", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">sadwaksdlmwalkjs;dlkw;laksldkwajmskdjklwkjamklsjdklwjalksjdklwjalksjdkwjmkasmkdmwkamlsdm;alskd;maciwmasndwanlskndwianslndwla</p></body></html>", nullptr));
        label_page_right_name_time->setText(QCoreApplication::translate("widget_message", "TextLabel", nullptr));
        label_page_right_img->setText(QCoreApplication::translate("widget_message", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widget_message: public Ui_widget_message {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_MESSAGE_H

/********************************************************************************
** Form generated from reading UI file 'widget_chat.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_CHAT_H
#define UI_WIDGET_CHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget_chat
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QTextEdit *textEdit_tosend;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_send;

    void setupUi(QWidget *widget_chat)
    {
        if (widget_chat->objectName().isEmpty())
            widget_chat->setObjectName("widget_chat");
        widget_chat->resize(609, 661);
        widget_chat->setMinimumSize(QSize(550, 600));
        widget_chat->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        verticalLayout = new QVBoxLayout(widget_chat);
        verticalLayout->setObjectName("verticalLayout");
        listWidget = new QListWidget(widget_chat);
        listWidget->setObjectName("listWidget");
        listWidget->setStyleSheet(QString::fromUtf8("QScrollBar:vertical{ \n"
"    width:16px;  \n"
"    border-style:flat;\n"
"    border-radius: 8px;\n"
"    border:0px;\n"
"    background: rgb(229, 229, 229);\n"
"} \n"
"QScrollBar::handle:vertical{ \n"
"    background: rgba(126,126,126,0.50);\n"
"    border-radius: 8px;\n"
"    width:16px; \n"
"    min-height:91px; \n"
"    border-style:flat;\n"
"}\n"
"QScrollBar::handle:vertical::hover{ \n"
"    background: rgba(85,85,85,0.90);\n"
"    border-radius: 8px;\n"
"    width:16px; \n"
"}\n"
"QScrollBar::handle:vertical::pressed{ \n"
"    background: rgba(85,85,85,0.90);\n"
"    border-radius:8px;\n"
"    width:16px; \n"
"}\n"
"QScrollBar::sub-page:vertical {\n"
"    background: rgb(229, 229, 229);\n"
"	border-style:flat;\n"
"}\n"
"QScrollBar::add-page:vertical {\n"
"	background: rgb(229, 229, 229);\n"
"	border-style:flat;\n"
"}\n"
"QScrollBar::add-line:vertical{\n"
"   background: rgb(229, 229, 229);\n"
"}\n"
"QScrollBar::sub-line:vertical {\n"
"   background: rgb(229, 229, 229);\n"
"}\n"
"/*\346\260\264\345\271\263"
                        "\346\273\232\345\212\250\346\235\241*/\n"
"QScrollBar:horizontal{ \n"
"    height:8px;  \n"
"    border-style:flat;\n"
"    border-radius: 4px;\n"
"    border:0px;\n"
"background: #19191A;\n"
"} \n"
"QScrollBar::handle:horizontal{ \n"
"    background: rgba(255,255,255,0.50);\n"
"    border-radius: 4px;\n"
"    height:8px; \n"
"    min-width:91px; \n"
"    border-style:flat;\n"
"}\n"
"QScrollBar::handle:horizontal::hover{ \n"
"    background: rgba(255,255,255,0.90);\n"
"    border-radius: 4px;\n"
"    height:8px; \n"
"}\n"
"QScrollBar::handle:horizontal::pressed{ \n"
"    background: rgba(255,255,255,0.90);\n"
"    border-radius:4px;\n"
"    height:8px; \n"
"}\n"
"QScrollBar::sub-page:horizontal {\n"
"    background: #19191A;\n"
"    border-style:flat;\n"
"}\n"
"QScrollBar::add-page:horizontal {\n"
"   background: #19191A;\n"
"    border-style:flat;\n"
"}\n"
"QScrollBar::sub-line:horizontal {\n"
"   background: #19191A;\n"
"}\n"
"QScrollBar::add-line:horizontal{\n"
"   background: #19191A;\n"
"}"));
        listWidget->setFrameShape(QFrame::Shape::NoFrame);

        verticalLayout->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton = new QPushButton(widget_chat);
        pushButton->setObjectName("pushButton");

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget_chat);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        textEdit_tosend = new QTextEdit(widget_chat);
        textEdit_tosend->setObjectName("textEdit_tosend");
        textEdit_tosend->setMaximumSize(QSize(16777215, 150));
        textEdit_tosend->setFrameShape(QFrame::Shape::StyledPanel);

        verticalLayout->addWidget(textEdit_tosend);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_send = new QPushButton(widget_chat);
        pushButton_send->setObjectName("pushButton_send");

        horizontalLayout_2->addWidget(pushButton_send);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(widget_chat);

        QMetaObject::connectSlotsByName(widget_chat);
    } // setupUi

    void retranslateUi(QWidget *widget_chat)
    {
        widget_chat->setWindowTitle(QCoreApplication::translate("widget_chat", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("widget_chat", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("widget_chat", "PushButton", nullptr));
        pushButton_send->setText(QCoreApplication::translate("widget_chat", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widget_chat: public Ui_widget_chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_CHAT_H

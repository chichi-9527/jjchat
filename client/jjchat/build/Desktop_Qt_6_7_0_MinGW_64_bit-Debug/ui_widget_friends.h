/********************************************************************************
** Form generated from reading UI file 'widget_friends.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_FRIENDS_H
#define UI_WIDGET_FRIENDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget_friends
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_chats;
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea_chats;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QWidget *tab_friends;
    QGridLayout *gridLayout_4;
    QToolBox *toolBox;
    QWidget *page_online;
    QGridLayout *gridLayout_5;
    QScrollArea *scrollArea_online;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout;
    QWidget *page_offline;
    QGridLayout *gridLayout_6;
    QScrollArea *scrollArea_offline;
    QWidget *scrollAreaWidgetContents_4;
    QVBoxLayout *verticalLayout_3;
    QWidget *tab_group;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea_groups;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_4;

    void setupUi(QWidget *widget_friends)
    {
        if (widget_friends->objectName().isEmpty())
            widget_friends->setObjectName("widget_friends");
        widget_friends->resize(312, 489);
        gridLayout = new QGridLayout(widget_friends);
        gridLayout->setObjectName("gridLayout");
        tabWidget = new QTabWidget(widget_friends);
        tabWidget->setObjectName("tabWidget");
        tab_chats = new QWidget();
        tab_chats->setObjectName("tab_chats");
        gridLayout_3 = new QGridLayout(tab_chats);
        gridLayout_3->setObjectName("gridLayout_3");
        scrollArea_chats = new QScrollArea(tab_chats);
        scrollArea_chats->setObjectName("scrollArea_chats");
        scrollArea_chats->setStyleSheet(QString::fromUtf8("QScrollArea{\n"
"border: 0px solid;\n"
"border-right-width: 1px;\n"
"border-right-color: #dcdbdc;\n"
"background-color: #ffffff;\n"
"}\n"
"QScrollBar:vertical {\n"
"border: none;\n"
"background: #f5f5f7;\n"
"width: 10px;\n"
"margin: 0px 0 0px 0;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"background: Gainsboro;\n"
"min-height: 20px;\n"
"border-radius: 5px;\n"
"border: none;\n"
"}\n"
"QScrollBar::add-line:vertical {\n"
"border: 0px solid grey;\n"
"background: #32CC99;\n"
"height: 0px;\n"
"subcontrol-position: bottom;\n"
"subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::sub-line:vertical {\n"
"border: 0px solid grey;\n"
"background: #32CC99;\n"
"height: 0px;\n"
"subcontrol-position: top;\n"
"subcontrol-origin: margin;\n"
"}\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"background: none;\n"
"width: 0px;\n"
"height: 0px;\n"
"}\n"
""));
        scrollArea_chats->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 270, 422));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName("verticalLayout_2");
        scrollArea_chats->setWidget(scrollAreaWidgetContents);

        gridLayout_3->addWidget(scrollArea_chats, 0, 0, 1, 1);

        tabWidget->addTab(tab_chats, QString());
        tab_friends = new QWidget();
        tab_friends->setObjectName("tab_friends");
        gridLayout_4 = new QGridLayout(tab_friends);
        gridLayout_4->setObjectName("gridLayout_4");
        toolBox = new QToolBox(tab_friends);
        toolBox->setObjectName("toolBox");
        page_online = new QWidget();
        page_online->setObjectName("page_online");
        page_online->setGeometry(QRect(0, 0, 272, 366));
        gridLayout_5 = new QGridLayout(page_online);
        gridLayout_5->setObjectName("gridLayout_5");
        scrollArea_online = new QScrollArea(page_online);
        scrollArea_online->setObjectName("scrollArea_online");
        scrollArea_online->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 252, 346));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout->setObjectName("verticalLayout");
        scrollArea_online->setWidget(scrollAreaWidgetContents_3);

        gridLayout_5->addWidget(scrollArea_online, 0, 0, 1, 1);

        toolBox->addItem(page_online, QString::fromUtf8("\345\234\250\347\272\277"));
        page_offline = new QWidget();
        page_offline->setObjectName("page_offline");
        page_offline->setGeometry(QRect(0, 0, 88, 88));
        gridLayout_6 = new QGridLayout(page_offline);
        gridLayout_6->setObjectName("gridLayout_6");
        scrollArea_offline = new QScrollArea(page_offline);
        scrollArea_offline->setObjectName("scrollArea_offline");
        scrollArea_offline->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName("scrollAreaWidgetContents_4");
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 68, 68));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents_4);
        verticalLayout_3->setObjectName("verticalLayout_3");
        scrollArea_offline->setWidget(scrollAreaWidgetContents_4);

        gridLayout_6->addWidget(scrollArea_offline, 0, 0, 1, 1);

        toolBox->addItem(page_offline, QString::fromUtf8("\347\246\273\347\272\277"));

        gridLayout_4->addWidget(toolBox, 0, 0, 1, 1);

        tabWidget->addTab(tab_friends, QString());
        tab_group = new QWidget();
        tab_group->setObjectName("tab_group");
        gridLayout_2 = new QGridLayout(tab_group);
        gridLayout_2->setObjectName("gridLayout_2");
        scrollArea_groups = new QScrollArea(tab_group);
        scrollArea_groups->setObjectName("scrollArea_groups");
        scrollArea_groups->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 270, 422));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        scrollArea_groups->setWidget(scrollAreaWidgetContents_2);

        gridLayout_2->addWidget(scrollArea_groups, 0, 0, 1, 1);

        tabWidget->addTab(tab_group, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(widget_friends);

        tabWidget->setCurrentIndex(0);
        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(widget_friends);
    } // setupUi

    void retranslateUi(QWidget *widget_friends)
    {
        widget_friends->setWindowTitle(QCoreApplication::translate("widget_friends", "Form", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_chats), QCoreApplication::translate("widget_friends", "\350\201\212\345\244\251", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_online), QCoreApplication::translate("widget_friends", "\345\234\250\347\272\277", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_offline), QCoreApplication::translate("widget_friends", "\347\246\273\347\272\277", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_friends), QCoreApplication::translate("widget_friends", "\346\234\213\345\217\213", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_group), QCoreApplication::translate("widget_friends", "\347\276\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widget_friends: public Ui_widget_friends {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_FRIENDS_H

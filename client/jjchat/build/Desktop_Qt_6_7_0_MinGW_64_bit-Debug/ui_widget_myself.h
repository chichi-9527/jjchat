/********************************************************************************
** Form generated from reading UI file 'widget_myself.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_MYSELF_H
#define UI_WIDGET_MYSELF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget_myself
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_avatar_img;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_username;
    QLabel *label_user_sigup_time;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *widget_myself)
    {
        if (widget_myself->objectName().isEmpty())
            widget_myself->setObjectName("widget_myself");
        widget_myself->resize(479, 126);
        widget_myself->setMinimumSize(QSize(0, 100));
        widget_myself->setMaximumSize(QSize(16777215, 126));
        horizontalLayout = new QHBoxLayout(widget_myself);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_avatar_img = new QLabel(widget_myself);
        label_avatar_img->setObjectName("label_avatar_img");
        label_avatar_img->setMinimumSize(QSize(100, 100));
        label_avatar_img->setMaximumSize(QSize(100, 100));

        verticalLayout->addWidget(label_avatar_img);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        label_username = new QLabel(widget_myself);
        label_username->setObjectName("label_username");

        verticalLayout_2->addWidget(label_username);

        label_user_sigup_time = new QLabel(widget_myself);
        label_user_sigup_time->setObjectName("label_user_sigup_time");

        verticalLayout_2->addWidget(label_user_sigup_time);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        retranslateUi(widget_myself);

        QMetaObject::connectSlotsByName(widget_myself);
    } // setupUi

    void retranslateUi(QWidget *widget_myself)
    {
        widget_myself->setWindowTitle(QCoreApplication::translate("widget_myself", "Form", nullptr));
        label_avatar_img->setText(QCoreApplication::translate("widget_myself", "TextLabel", nullptr));
        label_username->setText(QCoreApplication::translate("widget_myself", "TextLabel", nullptr));
        label_user_sigup_time->setText(QCoreApplication::translate("widget_myself", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widget_myself: public Ui_widget_myself {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_MYSELF_H

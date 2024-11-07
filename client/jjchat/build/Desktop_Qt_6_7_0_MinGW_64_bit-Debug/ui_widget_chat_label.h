/********************************************************************************
** Form generated from reading UI file 'widget_chat_label.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_CHAT_LABEL_H
#define UI_WIDGET_CHAT_LABEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget_chat_label
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label_img;
    QVBoxLayout *verticalLayout;
    QLabel *label_name;
    QLabel *label_discription;

    void setupUi(QWidget *widget_chat_label)
    {
        if (widget_chat_label->objectName().isEmpty())
            widget_chat_label->setObjectName("widget_chat_label");
        widget_chat_label->resize(513, 68);
        widget_chat_label->setMaximumSize(QSize(16777215, 68));
        horizontalLayout = new QHBoxLayout(widget_chat_label);
        horizontalLayout->setObjectName("horizontalLayout");
        label_img = new QLabel(widget_chat_label);
        label_img->setObjectName("label_img");
        label_img->setMinimumSize(QSize(50, 50));
        label_img->setMaximumSize(QSize(50, 50));

        horizontalLayout->addWidget(label_img);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_name = new QLabel(widget_chat_label);
        label_name->setObjectName("label_name");

        verticalLayout->addWidget(label_name);

        label_discription = new QLabel(widget_chat_label);
        label_discription->setObjectName("label_discription");

        verticalLayout->addWidget(label_discription);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(widget_chat_label);

        QMetaObject::connectSlotsByName(widget_chat_label);
    } // setupUi

    void retranslateUi(QWidget *widget_chat_label)
    {
        widget_chat_label->setWindowTitle(QCoreApplication::translate("widget_chat_label", "Form", nullptr));
        label_img->setText(QCoreApplication::translate("widget_chat_label", "TextLabel", nullptr));
        label_name->setText(QCoreApplication::translate("widget_chat_label", "TextLabel", nullptr));
        label_discription->setText(QCoreApplication::translate("widget_chat_label", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class widget_chat_label: public Ui_widget_chat_label {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_CHAT_LABEL_H

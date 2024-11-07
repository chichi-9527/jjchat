#include "widget_chat_label.h"
#include "ui_widget_chat_label.h"

widget_chat_label::widget_chat_label(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::widget_chat_label)
{
    ui->setupUi(this);
}

widget_chat_label::~widget_chat_label()
{
    delete ui;
}

void widget_chat_label::init_widget(widget_type type, unsigned long long id, int img_type, const char *img_path)
{
    _type = type;
    _id = id;
    if(img_type)
    {
        switch (img_type) {
        case 2:

            break;
        default:
            break;
        }
        return;
    }
    if(nullptr == img_path)
    {

        return;
    }

}

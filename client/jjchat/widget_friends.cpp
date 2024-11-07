#include "widget_friends.h"
#include "ui_widget_friends.h"

widget_friends::widget_friends(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::widget_friends)
{
    ui->setupUi(this);

}

widget_friends::~widget_friends()
{
    delete ui;
}

void widget_friends::add_widget_label(widget_chat_label::widget_type type, unsigned long long id, int ing_type, const char *img_path)
{

}

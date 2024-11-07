#include "widget_message.h"
#include "ui_widget_message.h"

widget_message::widget_message(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::widget_message)
    , _page_type(page_type::OTHER)
{
    ui->setupUi(this);

    _edit_default_height = 70;
    _edit_last_height = _edit_default_height;
    _this_widget_default_height = this->height();
}

widget_message::~widget_message()
{
    delete ui;
}

void widget_message::init(page_type type, QString message, unsigned long long user_id)
{
    _user_id = user_id;
    _page_type = type;
    if(_page_type == page_type::OTHER)
    {
        ui->stackedWidget->setCurrentWidget(ui->page_left);
        ui->textEdit_page_left->setText(message);
    }
    else {
        ui->stackedWidget->setCurrentWidget(ui->page_right);
        ui->textEdit_page_right->setText(message);
    }

    int now_height = 0;
    if(_page_type == page_type::OTHER)
    {
        now_height = ui->textEdit_page_left->document()->size().height();
        _edit_default_height = 70;
    }
    else
    {
        now_height = ui->textEdit_page_right->document()->size().height();
        _edit_default_height = 63;
    }
    if(now_height > _edit_last_height)
    {
        this->resize(this->width(), _this_widget_default_height + (now_height - _edit_last_height));
        _edit_last_height = now_height;
    }
}

void widget_message::resizeEvent(QResizeEvent *event)
{
    int now_height = 0;
    if(_page_type == page_type::OTHER)
    {
        now_height = ui->textEdit_page_left->document()->size().height();
        _edit_default_height = 70;
    }
    else
    {
        now_height = ui->textEdit_page_right->document()->size().height();
        _edit_default_height = 63;
    }


    if(now_height > _edit_last_height)
    {
        this->resize(this->width(), event->oldSize().height() + (now_height - _edit_last_height));
        _edit_last_height = now_height;
    }
    else if(now_height < _edit_last_height)
    {
        if(now_height > _edit_default_height)
        {
            this->resize(this->width(), event->oldSize().height() - (_edit_last_height - now_height));
            _edit_last_height = now_height;
        }
        else
        {
            this->resize(this->width(), _this_widget_default_height);
            _edit_last_height = _edit_default_height;
        }
    }
    emit widget_resize(this);
}

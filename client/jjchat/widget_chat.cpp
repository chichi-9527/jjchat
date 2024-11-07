#include "widget_chat.h"
#include "ui_widget_chat.h"

widget_chat::widget_chat(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::widget_chat)
    , _type(widget_type::PEOPLE)
{
    ui->setupUi(this);

    this->setAttribute(Qt::WA_QuitOnClose, false);

    for(int i = 0; i < 10; ++i)
    {
        add_message(widget_message::page_type::OTHER,
                    "QMap 提供了一个从类项为 key 的键到类项为T的直的映射，通常所存储的数据类型是一个键对应一个直，并且按照Key的次序存储数据，这个类也支持一键多值的情况，用类 QMultiMap。QMap 在 Qt 项目实际开发中经常用到，下面讲解一些其的常用方法。",
                    i);
    }
    for(int i = 0; i < 10; ++i)
    {
        add_message(widget_message::page_type::SELF,
                    "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111QMap 提供了一个从类项为 key 的键到类项为T的直的映射，通常所存储的数据类型是一个键对应一个直，并且按照Key的次序存储数据，这个类也支持一键多值的情况，用类 QMultiMap。QMap 在 Qt 项目实际开发中经常用到，下面讲解一些其的常用方法。",
                    i);
    }

}

widget_chat::~widget_chat()
{
    delete ui;
}

void widget_chat::add_message(widget_message::page_type type, QString message, unsigned long long id)
{
    widget_message* widget = new widget_message(this);
    QListWidgetItem* item = new QListWidgetItem(ui->listWidget);
    widget->init(type, message, id);
    item->setSizeHint(QSize(widget->width() -15, widget->height()));
    ui->listWidget->addItem(item);
    ui->listWidget->setItemWidget(item, widget);

    _msg_list_map.insert(widget, item);
    connect(widget, &widget_message::widget_resize, this, &widget_chat::_msg_widget_resize);
    ui->listWidget->setCurrentRow(ui->listWidget->count() - 1);
}

void widget_chat::insert_message(widget_message::page_type type, QString message, unsigned long long id, int row)
{
    widget_message* widget = new widget_message(this);
    QListWidgetItem* item = new QListWidgetItem();
    widget->init(type, message, id);
    item->setSizeHint(QSize(widget->width() -15, widget->height()));

    ui->listWidget->insertItem(row, item);
    ui->listWidget->setItemWidget(item, widget);

    _msg_list_map.insert(widget, item);
    connect(widget, &widget_message::widget_resize, this, &widget_chat::_msg_widget_resize);
}

void widget_chat::init(widget_type type, unsigned long long id)
{
    _type = type;
    _id = id;
}

widget_chat::widget_type widget_chat::get_type()
{
    return _type;
}

unsigned long long widget_chat::get_id()
{
    return _id;
}

void widget_chat::resizeEvent(QResizeEvent *e)
{
    QList<widget_message*> widget_list = _msg_list_map.keys();
    for(auto msg_widget : widget_list)
    {
        msg_widget->resize(e->size().width() , msg_widget->height());
    }
}

void widget_chat::_msg_widget_resize(widget_message *w)
{
    _msg_list_map.value(w)->setSizeHint(QSize(w->width() -15, w->height()));
}

void widget_chat::on_pushButton_send_clicked()
{
    QString message = ui->textEdit_tosend->toPlainText();
    if(message.size() == 0)
    {
        return;
    }
    ui->textEdit_tosend->clear();

    emit send_message(message, _id, _type);
}


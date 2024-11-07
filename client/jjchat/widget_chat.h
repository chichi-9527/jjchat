#ifndef WIDGET_CHAT_H
#define WIDGET_CHAT_H

#include <QWidget>
#include <QMap>
#include <QListWidgetItem>
#include <QList>
#include <QResizeEvent>
#include <QString>

#include "widget_message.h"

namespace Ui {
class widget_chat;
}

class widget_chat : public QWidget
{
    Q_OBJECT

public:
    explicit widget_chat(QWidget *parent = nullptr);
    ~widget_chat();

    enum class widget_type
    {
        GROUP,
        PEOPLE
    };

    void add_message(widget_message::page_type type, QString message, unsigned long long id = 0);
    void insert_message(widget_message::page_type type, QString message, unsigned long long id = 0, int row = 1);
    void init(widget_type type, unsigned long long id);

    widget_type get_type();
    unsigned long long get_id();

signals:
    void send_message(QString, unsigned long long, widget_type);

private:
    virtual void resizeEvent(QResizeEvent* e) override;

private slots:
    void _msg_widget_resize(widget_message* w);

    void on_pushButton_send_clicked();

private:
    Ui::widget_chat *ui;

    QMap<widget_message*, QListWidgetItem*> _msg_list_map;
    widget_type _type;
    // 群或个人的 id
    unsigned long long _id;
};

#endif // WIDGET_CHAT_H

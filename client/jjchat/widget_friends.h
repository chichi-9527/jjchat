#ifndef WIDGET_FRIENDS_H
#define WIDGET_FRIENDS_H

#include <QWidget>
#include <QList>

#include "widget_chat_label.h"

namespace Ui {
class widget_friends;
}

class widget_friends : public QWidget
{
    Q_OBJECT

public:
    explicit widget_friends(QWidget *parent = nullptr);
    ~widget_friends();

    void add_widget_label(widget_chat_label::widget_type type, unsigned long long id, int ing_type = 1, const char* img_path = nullptr);

private:
    Ui::widget_friends *ui;

    QList<widget_chat_label*> _list_widget_chats;
    QList<widget_chat_label*> _list_widget_friends_online;
    QList<widget_chat_label*> _list_widget_friends_offline;
    QList<widget_chat_label*> _list_widget_group;
};

#endif // WIDGET_FRIENDS_H

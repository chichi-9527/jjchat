#ifndef WIDGET_CHAT_LABEL_H
#define WIDGET_CHAT_LABEL_H

#include <QWidget>

namespace Ui {
class widget_chat_label;
}

class widget_chat_label : public QWidget
{
    Q_OBJECT

public:
    explicit widget_chat_label(QWidget *parent = nullptr);
    ~widget_chat_label();

    enum class widget_type{
        CHAT,
        FRINED_ONLINE,
        FRIEND_OFFLINE,
        GROUP
    };

    void init_widget(widget_type type, unsigned long long id, int img_type = 1, const char* img_path = nullptr);

private:
    Ui::widget_chat_label *ui;

    widget_type _type;
    unsigned long long _id;
};

#endif // WIDGET_CHAT_LABEL_H

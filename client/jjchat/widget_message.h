#ifndef WIDGET_MESSAGE_H
#define WIDGET_MESSAGE_H

#include <QWidget>
#include <QString>
#include <QResizeEvent>

namespace Ui {
class widget_message;
}

class widget_message : public QWidget
{
    Q_OBJECT

public:
    explicit widget_message(QWidget *parent = nullptr);
    ~widget_message();

    enum class page_type
    {
        OTHER,
        SELF
    };

    void init(page_type type, QString message, unsigned long long user_id);

signals:
    void widget_resize(widget_message*);

private:
    virtual void resizeEvent(QResizeEvent* event) override;

private:
    Ui::widget_message *ui;

    unsigned long long _user_id;

    int _edit_default_height;
    int _this_widget_default_height;
    int _edit_last_height;

    page_type _page_type;
};

#endif // WIDGET_MESSAGE_H

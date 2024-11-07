#ifndef WIDGET_MYSELF_H
#define WIDGET_MYSELF_H

#include <QWidget>

namespace Ui {
class widget_myself;
}

class widget_myself : public QWidget
{
    Q_OBJECT

public:
    explicit widget_myself(QWidget *parent = nullptr);
    ~widget_myself();

private:
    Ui::widget_myself *ui;
};

#endif // WIDGET_MYSELF_H

#include "widget_myself.h"
#include "ui_widget_myself.h"

widget_myself::widget_myself(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::widget_myself)
{
    ui->setupUi(this);
}

widget_myself::~widget_myself()
{
    delete ui;
}

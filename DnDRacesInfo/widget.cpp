#include "widget.h"
#include "ui_widget.h"
#include <QStyleOption>

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setInterfaceStyle();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setInterfaceStyle()
{
    this->setStyleSheet(StyleHelper::getMainWidgetStyle());

    setLabelStyle();

}

void Widget::setLabelStyle()
{
    ui->label->setStyleSheet(StyleHelper::getLabelStyle());
}

void Widget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}


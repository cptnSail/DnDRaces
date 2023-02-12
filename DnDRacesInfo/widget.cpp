#include "widget.h"
#include "ui_widget.h"
#include <QStyleOption>
#include <QLayout>
#include <QPixmap>

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
    setPortraitStyle();

}

void Widget::setLabelStyle()
{
    ui->label->setStyleSheet(StyleHelper::getLabelStyle());

    QGridLayout *grd = qobject_cast <QGridLayout*>(ui->gridLayout->layout());

    for (int row = 1; row < 4; row++) {
        for (int col = 0; col < 3; col++) {
            if (!(row == 2 && col == 1)) {
                QBoxLayout *box = qobject_cast <QBoxLayout*>(grd->itemAtPosition(row, col)->layout());
                QLabel *lb = qobject_cast <QLabel*>(box->itemAt(1)->widget());

                lb->setStyleSheet(StyleHelper::getNameStyle());
            }
        }
    }

    QPixmap pict(":/src/Icon.png");
    ui->Icon->setPixmap(pict);
}

void Widget::setPortraitStyle()
{
    setPortrait();

    QGridLayout *grd = qobject_cast <QGridLayout*>(ui->gridLayout->layout());

    for (int row = 1; row < 4; row++) {
        for (int col = 0; col < 3; col++) {
            if (!(row == 2 && col == 1)) {
                QBoxLayout *box = qobject_cast <QBoxLayout*>(grd->itemAtPosition(row, col)->layout());
                QPushButton *btn = qobject_cast <QPushButton*>(box->itemAt(0)->widget());

                btn->setStyleSheet(StyleHelper::getPortraitStyle());
            }
        }
    }
}

void Widget::setPortrait()
{
    QSize size(195, 194);
    ui->btnDwarf->setIconSize(size);
}

void Widget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}


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
    setBtnConnection();

    dbManager = new DataBaseManager;
    netManager = new NetworkManager;

    connect(dbManager, &DataBaseManager::dbIsEmpty, netManager, &NetworkManager::getNetData);
    connect(netManager, &NetworkManager::readComplete, dbManager, &DataBaseManager::getDataFromNet);

    dbManager->createDB();
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
    QSize size(ui->btnDwarf->width()-5, ui->btnDwarf->height()-6);
    QGridLayout *grd = qobject_cast <QGridLayout*>(ui->gridLayout->layout());

    for (int row = 1; row < 4; row++) {
        for (int col = 0; col < 3; col++) {
            if (!(row == 2 && col == 1)) {
                QBoxLayout *box = qobject_cast <QBoxLayout*>(grd->itemAtPosition(row, col)->layout());
                QPushButton *btn = qobject_cast <QPushButton*>(box->itemAt(0)->widget());

                btn->setStyleSheet(StyleHelper::getPortraitStyle());
                btn->setIconSize(size);
            }
        }
    }
}

void Widget::setBtnConnection()
{
    QGridLayout *grd = qobject_cast <QGridLayout*>(ui->gridLayout->layout());

    for (int row = 1; row < 4; row++) {
        for (int col = 0; col < 3; col++) {
            if (!(row == 2 && col == 1)) {
                QBoxLayout *box = qobject_cast <QBoxLayout*>(grd->itemAtPosition(row, col)->layout());
                QPushButton *btn = qobject_cast <QPushButton*>(box->itemAt(0)->widget());

                btn->setProperty("row", row);
                btn->setProperty("col", col);

                connect(btn, &QPushButton::clicked, this, &Widget::onBtnClicked);
            }
        }
    }
}

void Widget::createInfoWidget(QString name)
{
    iw = new InfoWidget;
    iw->setWindowTitle(name);

    iw->createInfo(name);

    iw->show();
}

void Widget::onBtnClicked()
{
    QPushButton *btn = qobject_cast <QPushButton*> (sender());
    QGridLayout *grid = qobject_cast <QGridLayout*>(ui->gridLayout->layout());

    int row = btn->property("row").toInt();
    int col = btn->property("col").toInt();

    QBoxLayout *box = qobject_cast <QBoxLayout*>(grid->itemAtPosition(row, col)->layout());
    QLabel *lb = qobject_cast <QLabel*>(box->itemAt(1)->widget());

    QString name = lb->text();

    createInfoWidget(name);
}


void Widget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
    QWidget::paintEvent(event);
}



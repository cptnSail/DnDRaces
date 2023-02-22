#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QPainter>
#include <stylehelper.h>
#include <networkmanager.h>
#include "databasemanager.h"
#include "infowidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void setInterfaceStyle();
    void setLabelStyle();
    void setPortraitStyle();

public slots:
    void createInfoWidget();
protected:
    void paintEvent(QPaintEvent *event);


private:
    Ui::Widget *ui;
    NetworkManager *netManager;
    DataBaseManager *dbManager;
    InfoWidget *iw;
};
#endif // WIDGET_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QPainter>
#include <stylehelper.h>
#include <networkmanager.h>

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
protected:
    void paintEvent(QPaintEvent *event);


private:
    Ui::Widget *ui;
    NetworkManager *manager;
};
#endif // WIDGET_H

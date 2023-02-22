#ifndef INFOWIDGET_H
#define INFOWIDGET_H

#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQueryModel>

namespace Ui {
class InfoWidget;
}

class InfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit InfoWidget(QWidget *parent = nullptr);
    ~InfoWidget();

    void createInfo(QString name);
    void setInfo();
private:
    Ui::InfoWidget *ui;
    QSqlQueryModel *model;
    QString editedText;
};

#endif // INFOWIDGET_H

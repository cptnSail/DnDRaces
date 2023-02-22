#ifndef INFOWINDOW_H
#define INFOWINDOW_H

#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class InfoWindow; }
QT_END_NAMESPACE

class InfoWindow : public QWidget
{
    Q_OBJECT

public:
    InfoWindow(QWidget *parent = 0);
    ~InfoWindow();

    void CreateInfo(QSqlDatabase *db);
private:
    Ui::InfoWindow *ui;
    QString editedText;
    QSqlTableModel *model;
};

#endif // INFOWINDOW_H

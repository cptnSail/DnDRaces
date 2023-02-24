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

    void createInfo(QString name); //Делает выборку из таблиц в соответсвии с полученным именем и формирует текст для нового окна
    void setInfo(); //Устанавливает сформированный текст в виджет TextEdit

    void editText(QSqlQueryModel *model, bool subrace = false); //Формирует из объекта таблицы удобный для чтения текст
    //Функции, редактирующие отдельные параметры объекта
    QString editTitle(QString text);
    QString editTraitsTitle(QString text);
    QString editSubDesc(QString text);
    QString editBaseInfo(QString text);
    QString editTraits(QString text);
    QString tinkerFix(QString text);
private:
    Ui::InfoWidget *ui;
    QSqlQueryModel *model;
    QSqlQueryModel *subModel;
    QString editedText;
};

#endif // INFOWIDGET_H

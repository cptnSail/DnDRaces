#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QJsonObject>
#include <QJsonArray>

class DataBaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DataBaseManager(QObject *p = 0);
    ~DataBaseManager();

    void fillDB(QJsonArray &jsonArr); //Переносит данные объектов QJsonArray в БД
    void addObject(QJsonObject &jsonOb, int subId); //Добавляет объект в основную таблицу
    void addSubObject(QJsonObject &jsonOb, int subId); //Добавляет объект в дополнительную таблицу
public slots:
    void createDB(); //Создаёт базу данных с двумя таблицами и отправляет сигнал для формирования get-запроса
    void getDataFromNet(QByteArray *ba); //Получает данные от класса NetworkManager и вызывает fillDB

signals:
    void dbIsEmpty();
private:
    void createRaceInfoTable(QSqlQuery *q); //Создаёт в БД основную таблицу
    void createSubraceTable(QSqlQuery *q); //Создаёт в БД дополнительную таблицу

    QSqlDatabase db;
    QSqlQuery *query;
};

#endif // DATABASEMANAGER_H

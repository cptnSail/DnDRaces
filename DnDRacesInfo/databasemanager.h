#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class DataBaseManager : public QObject
{
    Q_OBJECT
public:
    DataBaseManager(QObject *p = 0);
    ~DataBaseManager();

    void fillDB(QJsonArray &jsonArr);
    void addObject(QJsonObject &jsonOb, int subId);
    void addSubObject(QJsonObject &jsonOb, int subId);
public slots:
    void createDB();
    void getDataFromNet(QByteArray *ba);

signals:
    void dbIsEmpty();
private:
    void createRaceInfoTable(QSqlQuery *q);
    void createSubraceTable(QSqlQuery *q);

    QSqlDatabase db;
    QSqlQuery *query;
};

#endif // DATABASEMANAGER_H

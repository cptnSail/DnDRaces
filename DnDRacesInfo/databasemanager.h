#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "networkmanager.h"

class DataBaseManager : public QObject
{
    Q_OBJECT
public:
    DataBaseManager(QObject *p = 0);

    void fillDB(QJsonArray &jsonArr);
    void addObject(QJsonObject &jsonOb);
    void addSubObject(QJsonObject &jsonOb, int subId);
    void addSubId();
public slots:
    void getDataFromNet(QByteArray *ba);

signals:
    void dbIsEmpty();
private:
    void createDB();
    void createRaceInfoTable(QSqlQuery *q);
    void createSubraceTable(QSqlQuery *q);

    QSqlDatabase db;
    QSqlQuery *query;
};

#endif // DATABASEMANAGER_H

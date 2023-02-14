#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>

class DataBaseManager : public QObject
{
    Q_OBJECT
public:
    DataBaseManager(QObject *p = 0);

    void createDB();
    void addObject();
public slots:
    //void fillDB();
private:
    void createRaceInfoTable(QSqlQuery *q);
    void createSubraceTable(QSqlQuery *q);

    QSqlDatabase db;
    QSqlQuery *query;
};

#endif // DATABASEMANAGER_H

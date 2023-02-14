#include "databasemanager.h"
#include <QDebug>
#include <QSqlError>

DataBaseManager::DataBaseManager(QObject *p)
{
    Q_UNUSED(p)

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./RacesDB.db");

    createDB();
}

void DataBaseManager::createDB()
{
    db.open();
    if (db.isOpen() && db.tables().isEmpty()) {
        query = new QSqlQuery(db);
        createRaceInfoTable(query);
        createSubraceTable(query);

        delete query;

    } else if (db.isOpenError()) {
        qDebug() << db.lastError().databaseText();
    } else {
        qDebug() << "DB is alredy exists";
    }

    db.close();
}

void DataBaseManager::createRaceInfoTable(QSqlQuery *q)
{
    bool check = q->exec("create table raceInfo ("
                         "id integer primary key AUTOINCREMENT,"
                         "name text,"
                         "desc text,"
                         "asi_desc text,"
                         "speed_desc text,"
                         "vision text,"
                         "age text,"
                         "aligment text,"
                         "size text,"
                         "languages text,"
                         "traits text,"
                         "subrace integer,"
                         "FOREIGN KEY (subrace) REFERENCES subraces (id));");

    check ? qDebug() << "raceInfo was created" : qDebug() << q->lastError().databaseText();
}

void DataBaseManager::createSubraceTable(QSqlQuery *q)
{
    bool check = q->exec("create table subraces ("
                             "id integer primary key AUTOINCREMENT,"
                             "name text,"
                             "desc text,"
                             "asi_desc text,"
                             "traits text);");

    check ? qDebug() << "subraces was created" : qDebug() << q->lastError().databaseText();
}

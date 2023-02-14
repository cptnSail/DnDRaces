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

        emit dbIsEmpty();

        delete query;

    } else if (db.isOpenError()) {
        qDebug() << db.lastError().databaseText();
    } else {
        qDebug() << "DB is alredy exists";
    }

    db.close();
}

void DataBaseManager::addObject(QJsonObject &jsonOb, QSqlQuery *q)
{
    q->addBindValue(jsonOb.value("name").toString());
    q->addBindValue(jsonOb.value("desc").toString());
    q->addBindValue(jsonOb.value("asi_desc").toString());
    q->addBindValue(jsonOb.value("speed_desc").toString());
    q->addBindValue(jsonOb.value("vision").toString());
    q->addBindValue(jsonOb.value("age").toString());
    q->addBindValue(jsonOb.value("aligment").toString());
    q->addBindValue(jsonOb.value("size").toString());
    q->addBindValue(jsonOb.value("languages").toString());
    q->addBindValue(jsonOb.value("traits").toString());
}

void DataBaseManager::addSubObject(QJsonObject &jsonOb, QSqlQuery *q)
{

}

void DataBaseManager::getDataFromNet(QByteArray *ba)
{
    QJsonObject obj = QJsonDocument::fromJson(*ba).object();
    QJsonArray arr = obj.value("results").toArray();

    fillDB(arr);
}

void DataBaseManager::fillDB(QJsonArray &jsonArr)
{
    db.open();
    query = new QSqlQuery(db);

    for (auto element : jsonArr) {
        QJsonObject jsonOb = element.toObject();
        if (jsonOb.value("name").toString() != "Dragonborn") {
            query->prepare("insert into raceInfo (name, desc, asi_desc, speed_desc, vision, age,"
                                                 "aligment, size, languages, traits)"
                           "values (?,?,?,?,?,?,?,?,?,?)");

            addObject(jsonOb, query);

            if (query->exec())
                qDebug() << "Add object: " << jsonOb.value("name").toString();
            else
                qDebug() << query->lastError().databaseText();
        }
    }


    db.close();
    delete query;
}

void DataBaseManager::createRaceInfoTable(QSqlQuery *q)
{
    bool check = q->exec("create table raceInfo ("
                         "id integer primary key AUTOINCREMENT,"
                         "name text UNIQUE,"
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
                             "name text UNIQUE,"
                             "desc text,"
                             "asi_desc text,"
                             "traits text);");

    check ? qDebug() << "subraces was created" : qDebug() << q->lastError().databaseText();
}

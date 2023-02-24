#include "databasemanager.h"
#include <QDebug>
#include <QSqlError>
#include <QSqlTableModel>
#include <QJsonDocument>

DataBaseManager::DataBaseManager(QObject *p)
{
    Q_UNUSED(p)

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./RacesDB.db");
    db.open();
    query = new QSqlQuery(db);
}

DataBaseManager::~DataBaseManager()
{
    delete query;
    db.close();
}

void DataBaseManager::createDB()
{
    if (db.isOpen() && db.tables().isEmpty()) {
        createRaceInfoTable(query);
        createSubraceTable(query);

        emit dbIsEmpty();

    } else if (db.isOpenError()) {
        qDebug() << db.lastError().databaseText();
    } else {
        qDebug() << "DB is alredy exists";
    }
}

void DataBaseManager::addObject(QJsonObject &jsonOb, int subId)
{
    query->prepare("insert into raceInfo (name, desc, asi_desc, speed_desc, vision, age,"
                                         "alignment, size, languages, traits, subrace)"
                   "values (?,?,?,?,?,?,?,?,?,?,?)");

    query->addBindValue(jsonOb.value("name").toString());
    query->addBindValue(jsonOb.value("desc").toString());
    query->addBindValue(jsonOb.value("asi_desc").toString());
    query->addBindValue(jsonOb.value("speed_desc").toString());
    query->addBindValue(jsonOb.value("vision").toString());
    query->addBindValue(jsonOb.value("age").toString());
    query->addBindValue(jsonOb.value("alignment").toString());
    query->addBindValue(jsonOb.value("size").toString());
    query->addBindValue(jsonOb.value("languages").toString());
    query->addBindValue(jsonOb.value("traits").toString());
    if (!jsonOb.value("subraces").toArray().isEmpty())
        query->addBindValue(subId);
    else
        query->addBindValue("");

    if (!query->exec())
        qDebug() << query->lastError().databaseText();
}

void DataBaseManager::addSubObject(QJsonObject &jsonOb, int subId)
{
    query->prepare("insert into subraces (id, name, desc, asi_desc, traits)"
                   "values (?,?,?,?,?)");

    query->addBindValue(subId);
    query->addBindValue(jsonOb.value("name").toString());
    query->addBindValue(jsonOb.value("desc").toString());
    query->addBindValue(jsonOb.value("asi_desc").toString());
    query->addBindValue(jsonOb.value("traits").toString());

    if (!query->exec())
        qDebug() << query->lastError().databaseText();
}

void DataBaseManager::getDataFromNet(QByteArray *ba)
{
    QJsonObject obj = QJsonDocument::fromJson(*ba).object();
    QJsonArray arr = obj.value("results").toArray();

    fillDB(arr);
}

void DataBaseManager::fillDB(QJsonArray &jsonArr)
{
    int idCount = 1;

    for (auto element : jsonArr) {
        QJsonObject jsonOb = element.toObject();
        if (jsonOb.value("name").toString() != "Dragonborn") {

            addObject(jsonOb, idCount);

            if (!jsonOb.value("subraces").toArray().isEmpty()) {
                jsonOb = jsonOb.value("subraces").toArray().first().toObject();
                addSubObject(jsonOb, idCount);
                idCount++;
            }
        }
    }
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
                         "alignment text,"
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
                             "id integer primary key,"
                             "name text UNIQUE,"
                             "desc text,"
                             "asi_desc text,"
                             "traits text);");

    check ? qDebug() << "subraces was created" : qDebug() << q->lastError().databaseText();
}

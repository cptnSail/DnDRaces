#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QByteArray>

class NetworkManager : public QObject
{
    Q_OBJECT
public:
    explicit NetworkManager(QObject *p = 0);
    ~NetworkManager();

public slots:
    void getNetData(); //get-запрос
    void setData(QNetworkReply *reply); //Передача полученных данных в netData и вызов сигнала для передачи данных в класс DataBaseManager

signals:
    void readComplete(QByteArray *ba);

private:
    QNetworkAccessManager *manager;
    QByteArray netData;
};

#endif // NETWORKMANAGER_H

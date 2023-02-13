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
    QByteArray getData();

public slots:
    void getNetData();
    void setData(QNetworkReply *reply);

signals:
    void readComplet();

private:
    QNetworkAccessManager *manager;
    QByteArray netData;
};

#endif // NETWORKMANAGER_H

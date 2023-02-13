#include "networkmanager.h"
#include <QDebug>

NetworkManager::NetworkManager(QObject *p)
{
    Q_UNUSED(p)

    manager = new QNetworkAccessManager;
    connect(manager, &QNetworkAccessManager::finished, this, &NetworkManager::setData);

    netData.clear();
    getNetData();
}

void NetworkManager::getNetData()
{
    QNetworkRequest request(QUrl(QString("https://api.open5e.com/races/")));
    manager->get(request);
}

void NetworkManager::setData(QNetworkReply *reply)
{
    if (!reply->error()) {
        netData.append(reply->readAll());
        qDebug() << "Data was readed";
    } else
        qDebug() << reply->errorString();
}

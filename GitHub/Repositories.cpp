//
// Created by matt on 12/05/16.
//

#include "Repositories.h"

Repository::Repository(std::string name) {
    this->name = name;
}

Repositories::Repositories(AccountData *account) {
    this->account = account;
}

void Repositories::loadData() {
    QEventLoop eventLoop;
    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    QString request_url = QString().fromStdString(account->getReposUri());
    QNetworkRequest req( QUrl( QString().fromStdString(request_url.toStdString()) ) );
    QNetworkReply *reply = mgr.get(req);
    eventLoop.exec();
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray strReply = reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply);
        QJsonArray jsonArray = jsonResponse.array();
        qDebug() << jsonArray.count();
        delete reply;
        foreach (const QJsonValue & value, jsonArray) {
            QJsonObject repo = value.toObject();
            qDebug() << repo["name"].toString();
        }
    }
    else {
        //failure
        std::cout << "Failure " << reply->errorString().toStdString();
        delete reply;
    }
}
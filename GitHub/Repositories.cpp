//
// Created by matt on 12/05/16.
//

#include "Repositories.h"

Repository::Repository(AccountData *account) {
    this->account = account;
}

void Repository::loadFromObject(QJsonObject data) {
    id = data["id"].toInt();
    name = data["name"].toString().toStdString();
    _private = data["privare"].toBool();
    _fork = data["fork"].toBool();
    home_url = data["url"].toString().toStdString();
    commits_url = account->addAuthToURL(data["commits_url"].toString().toStdString());
    branches_url = account->addAuthToURL(data["branches_url"].toString().toStdString());
    description = data["description"].toString().toStdString();
    language = data["language"].toString().toStdString();
}

std::string Repository::getName() {
    return name;
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
                Repository *tmpRepo = new Repository(account);
                tmpRepo->loadFromObject(repo);
                repos.append(tmpRepo);
        }
    }
    else {
        //failure
        std::cout << "Failure " << reply->errorString().toStdString();
        delete reply;
    }

    foreach(Repository *r, repos) qDebug() << QString().fromStdString(r->getName());

}
//
// Created by matt on 12/05/16.
//

#ifndef GITHUBDATA_REPOSITORIES_H
#define GITHUBDATA_REPOSITORIES_H
#include <iostream>
#include <string>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QVariantMap>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QLinkedList>
#include "Account.h"

class Repository{
public:
    Repository(std::string name);

private:
    std::string name;

};


class Repositories{
public:
    Repositories(AccountData *account);

private:
    AccountData *account;
    QLinkedList<Repository *> repos;
    void loadData();
};


#endif //GITHUBDATA_REPOSITORIES_H

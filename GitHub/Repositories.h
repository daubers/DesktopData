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
    Repository(AccountData *account);
    void loadFromObject(QJsonObject data);
    std::string getName();
private:
    AccountData *account;
    std::string name;
    long id;
    bool _private;
    bool _fork;
    std::string home_url;
    std::string commits_url;
    std::string branches_url;
    std::string description;
    std::string language;
};


class Repositories{
public:
    Repositories(AccountData *account);
    void loadData();

private:
    AccountData *account;
    QLinkedList<Repository *> repos;
};


#endif //GITHUBDATA_REPOSITORIES_H

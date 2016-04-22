//
// Created by matt on 16/04/16.
//

#ifndef GITHUBDATA_ACCOUNT_H
#define GITHUBDATA_ACCOUNT_H

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


class AccountData{
public:
    const static int AUTH_OAUTH    = 1;
    const static int AUTH_PASSWORD = 2;

    AccountData(std::string username, std::string password);
    AccountData(std::string oauth_token);
    void loadData();
    int authType();
    std::string getUsername();
    std::string getCreatedAt();
    std::string getAvatarUrl();
    int getId();

private:
    int auth_type;
    std::string account_username;
    std::string account_password;
    std::string account_oauth_token;
    int github_id;

};
#endif //GITHUBDATA_ACCOUNT_H

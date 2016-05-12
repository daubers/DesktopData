//
// Created by matt on 16/04/16.
//

#include "Account.h"

AccountData::AccountData(std::string username, std::string password){
    auth_type = AccountData::AUTH_PASSWORD;
    account_username = username;
    account_password = password;
}

AccountData::AccountData(std::string oauth_token) {
    auth_type = AccountData::AUTH_OAUTH;
    account_oauth_token = oauth_token;
}

std::string AccountData::addAuthToURL(std::string url){
    QString request_url;
    if (auth_type == AccountData::AUTH_OAUTH) {
        request_url = QString().fromStdString(url);
        request_url = request_url.append("?access_token=");
        request_url = request_url.append(QString().fromStdString(account_oauth_token));
    }
    else {
        QString tmp_url = QString().fromStdString(url).remove("https://");
        request_url = QString("https://").append(QString().fromStdString(account_username));
        request_url = request_url.append(QString(":"));
        request_url = request_url.append(QString().fromStdString(account_password));
        request_url = request_url.append("@");
        request_url = request_url.append(tmp_url);
    }
    return request_url.toStdString();
}

void AccountData::loadData() {
    QEventLoop eventLoop;

    QNetworkAccessManager mgr;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));
    std::string url = addAuthToURL("https://api.github.com/user");
    QString request_url = QString().fromStdString(url);
    QNetworkRequest req( QUrl( QString().fromStdString(request_url.toStdString()) ) );
    QNetworkReply *reply = mgr.get(req);
    eventLoop.exec();
    if (reply->error() == QNetworkReply::NoError) {
        //success
        QByteArray strReply = reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply);
        QJsonObject jsonObj = jsonResponse.object();
        std::cout << "Success login is " << jsonObj["login"].toString().toStdString();
        std::cout << strReply.toStdString();
        std::cout << "\n";
        account_username = jsonObj["login"].toString().toStdString();
        name = jsonObj["name"].toString().toStdString();
        company = jsonObj["company"].toString().toStdString();
        public_repos = jsonObj["public_repos"].toInt();
        avatar_url = jsonObj["avatar_url"].toString().toStdString();
        repos_url = addAuthToURL(jsonObj["repos_url"].toString().toStdString());
        std::cout << repos_url;

        delete reply;
    }
    else {
        //failure
        std::cout << "Failure " << reply->errorString().toStdString();
        delete reply;
    }
}

int AccountData::authType() { return auth_type; }

int AccountData::getId() { return github_id; }

int AccountData::getNoPrivateRepos() { return total_private_repos; }

int AccountData::getNoPublicRepos() { return public_repos; }

int AccountData::getNoPublicGists() { return public_gists; }

int AccountData::getNoFollowers() { return followers; }

int AccountData::getNoFollowing() { return following; }

std::string AccountData::getAvatarUrl() { return avatar_url; }

std::string AccountData::getCompany() { return company; }

std::string AccountData::getCreatedAt() { return created_at; }

std::string AccountData::getEmail() { return email; }

std::string AccountData::getGithubLink() { return html_url; }

std::string AccountData::getName() { return name; }

std::string AccountData::getReposUri() { return repos_url; }

std::string AccountData::getUsername() { return account_username; }

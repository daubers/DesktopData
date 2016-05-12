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
    std::string getGithubLink();
    std::string getReposUri();
    std::string getName();
    std::string getCompany();
    std::string getEmail();
    int getNoPublicRepos();
    int getNoPrivateRepos();
    int getNoPublicGists();
    int getNoFollowers();
    int getNoFollowing();
    int getId();

private:
    int auth_type;
    std::string account_username;
    std::string account_password;
    std::string account_oauth_token;
    std::string avatar_url;
    std::string html_url;
    std::string repos_url;
    std::string name;
    std::string company;
    std::string email;
    int public_repos;
    int public_gists;
    int followers;
    int following;
    int total_private_repos;
    std::string created_at;
    std::string updated_at;
    int github_id;
    std::string addAuthToURL(std::string url);
};
#endif //GITHUBDATA_ACCOUNT_H

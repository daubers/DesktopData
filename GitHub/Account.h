//
// Created by matt on 16/04/16.
//

#ifndef GITHUBDATA_ACCOUNT_H
#define GITHUBDATA_ACCOUNT_H
#include <string>



class AccountData{
public:
    const static int AUTH_OAUTH    = 1;
    const static int AUTH_PASSWORD = 2;

    AccountData(std::string username, std::string password);
    AccountData(std::string oauth_token);
    int authType();
    std::string getUsername();
    std::string getCreatedAt();
    std::string getAvatarUrl();
    int getId();
private:
    int auth_type;
    std::string username;
    std::string password;
    std::string oauth_token;
    int github_id;

};
#endif //GITHUBDATA_ACCOUNT_H

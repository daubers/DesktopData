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


}
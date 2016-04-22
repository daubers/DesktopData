#include <QApplication>
#include <QPushButton>
#include "GitHub/Account.h"

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    QPushButton button ("Hello world !");
    button.show();

    AccountData *account = new AccountData("personalised_github_key");
    account->loadData();
    return app.exec();
}
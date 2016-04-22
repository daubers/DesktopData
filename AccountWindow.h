//
// Created by matt on 22/04/16.
//

#ifndef GITHUBDATA_ACCOUNTWINDOW_H
#define GITHUBDATA_ACCOUNTWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include "GitHub/Account.h"

class QPushButton;
class AccountWindow : public QWidget
{
public:
    explicit AccountWindow(QWidget *parent = 0);
    void setApiKey(std::string apikey);
private:
    QPushButton *m_button;
    QLineEdit *api_key;
    QGridLayout *layout;
    std::string apikey;
    AccountData *acctData;
};


#endif //GITHUBDATA_ACCOUNTWINDOW_H

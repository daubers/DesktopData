//
// Created by matt on 22/04/16.
//

#ifndef GITHUBDATA_ACCOUNTWINDOW_H
#define GITHUBDATA_ACCOUNTWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QComboBox>
#include <QGroupBox>
#include <QLabel>
#include "GitHub/Account.h"

class QPushButton;
class AccountWindow : public QWidget
{
    Q_OBJECT
public:
    explicit AccountWindow(QWidget *parent = 0);
    void setApiKey(std::string apikey);
private:
    void setAvatar();
    QLineEdit *api_key;
    QGridLayout *layout;
    QComboBox *options;
    std::string apikey;
    AccountData *acctData;
    QGroupBox *dataBox;
    QGridLayout *accountDataLayout;
    QLabel *lblUsername;
    QLabel *username;
    QLabel *lblRealName;
    QLabel *realName;
    QLabel *lblCompany;
    QLabel *company;
    QLabel *lblPublicRepos;
    QLabel *publicRepos;
    QLabel *avatar;

private slots:
    void on_combobox_change(const QString &text);
    void on_nm_label_download(QNetworkReply *reply);
};


#endif //GITHUBDATA_ACCOUNTWINDOW_H

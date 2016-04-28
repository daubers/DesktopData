//
// Created by matt on 22/04/16.
//

#ifndef GITHUBDATA_ACCOUNTWINDOW_H
#define GITHUBDATA_ACCOUNTWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include <QComboBox>
#include "GitHub/Account.h"

class QPushButton;
class AccountWindow : public QWidget
{
    Q_OBJECT
public:
    explicit AccountWindow(QWidget *parent = 0);
    void setApiKey(std::string apikey);
private:
    QLineEdit *api_key;
    QGridLayout *layout;
    QComboBox *options;
    std::string apikey;
    AccountData *acctData;

private slots:
    void on_combobox_change(const QString &text);
};


#endif //GITHUBDATA_ACCOUNTWINDOW_H

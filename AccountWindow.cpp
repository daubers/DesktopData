//
// Created by matt on 22/04/16.
//

#include "AccountWindow.h"

AccountWindow::AccountWindow(QWidget *parent) :
        QWidget(parent)
{
    // Create and position the button
    layout = new QGridLayout;
    options = new QComboBox();
    api_key = new QLineEdit();

    options->addItem("Account Information");
    options->addItem("Repo Statistics");
    layout->addWidget(options, 0 ,0);

    dataBox = new QGroupBox("Account Data");
    dataBox->setMaximumSize(250, 200);
    layout->addWidget(dataBox, 1 ,0);

    accountDataLayout = new QGridLayout;
    lblUsername = new QLabel("Username");
    username = new QLabel();
    accountDataLayout->addWidget(lblUsername, 0, 0);
    accountDataLayout->addWidget(username, 0, 1);

    lblRealName = new QLabel("Real Name");
    realName = new QLabel();
    accountDataLayout->addWidget(lblRealName, 1, 0);
    accountDataLayout->addWidget(realName, 1, 1);

    dataBox->setLayout(accountDataLayout);

    this->setLayout(layout);
    //connect the option box changing signal up to the right function
    connect(options, SIGNAL (currentTextChanged(const QString)), this, SLOT (on_combobox_change(const QString)));
}

void AccountWindow::setApiKey(std::string apikey) {
    this->apikey = apikey;
    this->api_key->setText(QString().fromStdString(apikey));
    acctData = new AccountData(this->api_key->text().toStdString());
    acctData->loadData();
    username->setText(QString().fromStdString(acctData->getUsername()));
    realName->setText(QString().fromStdString(acctData->getName()));
}

void AccountWindow::on_combobox_change(const QString &text) {
    qDebug() << text;
}
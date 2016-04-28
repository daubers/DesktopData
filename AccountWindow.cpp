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
    this->setLayout(layout);
    //connect the option box changing signal up to the right function
    connect(options, SIGNAL (currentTextChanged(const QString)), this, SLOT (on_combobox_change(const QString)));
}

void AccountWindow::setApiKey(std::string apikey) {
    this->apikey = apikey;
    this->api_key->setText(QString().fromStdString(apikey));
    acctData = new AccountData(this->api_key->text().toStdString());
    acctData->loadData();
}

void AccountWindow::on_combobox_change(const QString &text) {
    qDebug() << text;
}
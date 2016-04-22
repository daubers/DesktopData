//
// Created by matt on 22/04/16.
//

#include "AccountWindow.h"
#include <QPushButton>
#include <QString>


AccountWindow::AccountWindow(QWidget *parent) :
        QWidget(parent)
{
    // Create and position the button
    layout = new QGridLayout;
    api_key = new QLineEdit();
    m_button = new QPushButton("Hello World");
    m_button->setGeometry(10, 10, 80, 30);
    layout->addWidget(api_key, 0 ,0);
    layout->addWidget(m_button, 0, 1);
    this->setLayout(layout);
}

void AccountWindow::setApiKey(std::string apikey) {
    this->apikey = apikey;
    this->api_key->setText(QString().fromStdString(apikey));
    acctData = new AccountData(this->api_key->text().toStdString());
    acctData->loadData();
}
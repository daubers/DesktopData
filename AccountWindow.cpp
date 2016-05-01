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
    avatar = new QLabel();
    avatar->setMaximumSize(100,100);

    options->addItem("Account Information");
    options->addItem("Repo Statistics");
    layout->addWidget(options, 0 ,0);

    dataBox = new QGroupBox("Account Data");
    dataBox->setMaximumSize(400, 400);
    layout->addWidget(dataBox, 1 ,0);

    accountDataLayout = new QGridLayout;

    accountDataLayout->addWidget(avatar, 0, 2, 3, 3);

    lblUsername = new QLabel("Username");
    username = new QLabel();
    accountDataLayout->addWidget(lblUsername, 0, 0);
    accountDataLayout->addWidget(username, 0, 1);

    lblRealName = new QLabel("Real Name");
    realName = new QLabel();
    accountDataLayout->addWidget(lblRealName, 1, 0);
    accountDataLayout->addWidget(realName, 1, 1);

    lblCompany = new QLabel("Company");
    company = new QLabel();
    accountDataLayout->addWidget(lblCompany, 2, 0);
    accountDataLayout->addWidget(company, 2, 1);

    lblPublicRepos = new QLabel("Public Repos");
    publicRepos = new QLabel();
    accountDataLayout->addWidget(lblPublicRepos, 3, 0);
    accountDataLayout->addWidget(publicRepos, 3, 1);


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
    company->setText(QString().fromStdString(acctData->getCompany()));
    publicRepos->setText(QString().number(acctData->getNoPublicRepos()));
    this->setAvatar();
}

void AccountWindow::setAvatar() {
    QNetworkAccessManager *m_netwManager = new QNetworkAccessManager(this);
    connect(m_netwManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(on_nm_label_download(QNetworkReply*)));

    QUrl url(QString().fromStdString(this->acctData->getAvatarUrl()));
    QNetworkRequest request(url);
    m_netwManager->get(request);
}

void AccountWindow::on_combobox_change(const QString &text) {
    qDebug() << text;
}

void AccountWindow::on_nm_label_download(QNetworkReply *reply){
    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << "Error in" << reply->url() << ":" << reply->errorString();
        return;
    }

    QByteArray jpegData = reply->readAll();
    QPixmap pixmap;
    pixmap.loadFromData(jpegData);
    avatar->setPixmap(pixmap.scaledToHeight(100));

}
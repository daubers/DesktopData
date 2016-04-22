//
// Created by matt on 22/04/16.
//

#include "LoginWindow.h"

Window::Window(QWidget *parent) :
        QWidget(parent)
{
    // Create and position the button
    layout = new QGridLayout;
    api_key = new QLineEdit();
    m_button = new QPushButton("Hello World");
    m_button->setGeometry(10, 10, 80, 30);
    layout->addWidget(api_key, 0 ,0);
    layout->addWidget(m_button, 0, 1);
    connect(m_button, SIGNAL (released()), this, SLOT (loginButtonClicked()));
    this->setLayout(layout);
}

void Window::loginButtonClicked() {
    AccountWindow *accntWindow = new AccountWindow;
    accntWindow->setApiKey(api_key->text().toStdString());
    accntWindow->show();
    this->hide();
}
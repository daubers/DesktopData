//
// Created by matt on 22/04/16.
//

#ifndef GITHUBDATA_LOGINWINDOW_H
#define GITHUBDATA_LOGINWINDOW_H

#include <QWidget>
#include <QLineEdit>
#include <QGridLayout>
#include "AccountWindow.h"
#include <QPushButton>

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = 0);

private slots:
    void loginButtonClicked();
private:
    QPushButton *m_button;
    QLineEdit *api_key;
    QGridLayout *layout;
};

#endif //GITHUBDATA_ACCOUNTWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_logIn
{
public:
    QLabel *userName_lbl;
    QLabel *password_lbl;
    QLineEdit *userName_le;
    QLineEdit *password_le;
    QPushButton *pushButton;

    void setupUi(QDialog *logIn)
    {
        if (logIn->objectName().isEmpty())
            logIn->setObjectName(QStringLiteral("logIn"));
        logIn->resize(400, 300);
        userName_lbl = new QLabel(logIn);
        userName_lbl->setObjectName(QStringLiteral("userName_lbl"));
        userName_lbl->setGeometry(QRect(53, 70, 71, 20));
        password_lbl = new QLabel(logIn);
        password_lbl->setObjectName(QStringLiteral("password_lbl"));
        password_lbl->setGeometry(QRect(53, 100, 71, 20));
        userName_le = new QLineEdit(logIn);
        userName_le->setObjectName(QStringLiteral("userName_le"));
        userName_le->setGeometry(QRect(140, 60, 113, 25));
        password_le = new QLineEdit(logIn);
        password_le->setObjectName(QStringLiteral("password_le"));
        password_le->setGeometry(QRect(140, 90, 113, 25));
        pushButton = new QPushButton(logIn);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 160, 80, 25));

        retranslateUi(logIn);

        QMetaObject::connectSlotsByName(logIn);
    } // setupUi

    void retranslateUi(QDialog *logIn)
    {
        logIn->setWindowTitle(QApplication::translate("logIn", "Dialog", Q_NULLPTR));
        userName_lbl->setText(QApplication::translate("logIn", "User Name:", Q_NULLPTR));
        password_lbl->setText(QApplication::translate("logIn", "Password:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("logIn", "Log In", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class logIn: public Ui_logIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H

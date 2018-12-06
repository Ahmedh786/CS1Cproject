/********************************************************************************
** Form generated from reading UI file 'contact.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACT_H
#define UI_CONTACT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_contact
{
public:
    QLabel *logo_pic;

    void setupUi(QDialog *contact)
    {
        if (contact->objectName().isEmpty())
            contact->setObjectName(QStringLiteral("contact"));
        contact->resize(400, 300);
        contact->setAutoFillBackground(true);
        logo_pic = new QLabel(contact);
        logo_pic->setObjectName(QStringLiteral("logo_pic"));
        logo_pic->setGeometry(QRect(90, 80, 221, 151));
        logo_pic->setPixmap(QPixmap(QString::fromUtf8("logo.png")));

        retranslateUi(contact);

        QMetaObject::connectSlotsByName(contact);
    } // setupUi

    void retranslateUi(QDialog *contact)
    {
        contact->setWindowTitle(QApplication::translate("contact", "Contact Us", Q_NULLPTR));
        logo_pic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class contact: public Ui_contact {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACT_H

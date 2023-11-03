/********************************************************************************
** Form generated from reading UI file 'rooster.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOSTER_H
#define UI_ROOSTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Rooster
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Rooster)
    {
        if (Rooster->objectName().isEmpty())
            Rooster->setObjectName(QString::fromUtf8("Rooster"));
        Rooster->resize(400, 300);
        pushButton = new QPushButton(Rooster);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 200, 75, 24));
        pushButton_2 = new QPushButton(Rooster);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 210, 75, 24));

        retranslateUi(Rooster);

        QMetaObject::connectSlotsByName(Rooster);
    } // setupUi

    void retranslateUi(QWidget *Rooster)
    {
        Rooster->setWindowTitle(QCoreApplication::translate("Rooster", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Rooster", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Rooster", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Rooster: public Ui_Rooster {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOSTER_H

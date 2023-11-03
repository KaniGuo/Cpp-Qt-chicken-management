/********************************************************************************
** Form generated from reading UI file 'eggdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EGGDIALOG_H
#define UI_EGGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EggDialog
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAddNew;
    QPushButton *btnInsert;
    QPushButton *btnSave;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btnDelete;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnClose;

    void setupUi(QDialog *EggDialog)
    {
        if (EggDialog->objectName().isEmpty())
            EggDialog->setObjectName(QString::fromUtf8("EggDialog"));
        EggDialog->resize(926, 466);
        layoutWidget = new QWidget(EggDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 911, 451));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setSortingEnabled(true);

        verticalLayout->addWidget(tableView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnAddNew = new QPushButton(layoutWidget);
        btnAddNew->setObjectName(QString::fromUtf8("btnAddNew"));

        horizontalLayout->addWidget(btnAddNew);

        btnInsert = new QPushButton(layoutWidget);
        btnInsert->setObjectName(QString::fromUtf8("btnInsert"));

        horizontalLayout->addWidget(btnInsert);

        btnSave = new QPushButton(layoutWidget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));

        horizontalLayout->addWidget(btnSave);

        horizontalSpacer_4 = new QSpacerItem(13, 68, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        btnDelete = new QPushButton(layoutWidget);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));

        horizontalLayout->addWidget(btnDelete);

        horizontalSpacer_2 = new QSpacerItem(13, 68, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btnClose = new QPushButton(layoutWidget);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));

        horizontalLayout->addWidget(btnClose);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(EggDialog);
        QObject::connect(btnClose, &QPushButton::clicked, EggDialog, qOverload<>(&QDialog::close));

        QMetaObject::connectSlotsByName(EggDialog);
    } // setupUi

    void retranslateUi(QDialog *EggDialog)
    {
        EggDialog->setWindowTitle(QCoreApplication::translate("EggDialog", "Dialog", nullptr));
        btnAddNew->setText(QCoreApplication::translate("EggDialog", "Neu", nullptr));
        btnInsert->setText(QCoreApplication::translate("EggDialog", "Einf\303\274gen", nullptr));
        btnSave->setText(QCoreApplication::translate("EggDialog", "Speichern", nullptr));
        btnDelete->setText(QCoreApplication::translate("EggDialog", "L\303\266schen", nullptr));
        btnClose->setText(QCoreApplication::translate("EggDialog", "Schlie\303\237en", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EggDialog: public Ui_EggDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EGGDIALOG_H

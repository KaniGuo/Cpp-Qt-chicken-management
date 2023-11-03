/********************************************************************************
** Form generated from reading UI file 'sprachedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPRACHEDIALOG_H
#define UI_SPRACHEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpracheDialog
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QRadioButton *rdGerman;
    QRadioButton *rdEnglish;
    QWidget *tab_2;

    void setupUi(QDialog *SpracheDialog)
    {
        if (SpracheDialog->objectName().isEmpty())
            SpracheDialog->setObjectName(QString::fromUtf8("SpracheDialog"));
        SpracheDialog->resize(377, 308);
        tabWidget = new QTabWidget(SpracheDialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 20, 341, 271));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        rdGerman = new QRadioButton(tab);
        rdGerman->setObjectName(QString::fromUtf8("rdGerman"));

        gridLayout->addWidget(rdGerman, 0, 0, 1, 1);

        rdEnglish = new QRadioButton(tab);
        rdEnglish->setObjectName(QString::fromUtf8("rdEnglish"));

        gridLayout->addWidget(rdEnglish, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        retranslateUi(SpracheDialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SpracheDialog);
    } // setupUi

    void retranslateUi(QDialog *SpracheDialog)
    {
        SpracheDialog->setWindowTitle(QCoreApplication::translate("SpracheDialog", "Dialog", nullptr));
        rdGerman->setText(QCoreApplication::translate("SpracheDialog", "Deutsch", nullptr));
        rdEnglish->setText(QCoreApplication::translate("SpracheDialog", "Englisch", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("SpracheDialog", "Sprache", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("SpracheDialog", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SpracheDialog: public Ui_SpracheDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPRACHEDIALOG_H

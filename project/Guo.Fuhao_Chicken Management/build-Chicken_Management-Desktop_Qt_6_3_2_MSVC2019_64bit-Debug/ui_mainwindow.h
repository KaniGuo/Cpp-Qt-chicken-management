/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_Sprache;
    QWidget *centralwidget;
    QLabel *lbname;
    QLabel *lbpic;
    QLabel *lbtitle;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rbRooster;
    QComboBox *cboRooster;
    QLineEdit *letRooster;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *rbHen;
    QComboBox *cboHen;
    QLineEdit *leHen;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *rbEgg;
    QComboBox *cboEgg;
    QLineEdit *letEgg;
    QPushButton *btnSearch;
    QTableView *tableView;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btncfgRooster;
    QPushButton *btncfgHen;
    QPushButton *btncfgEgg;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnClose;
    QMenuBar *menubar;
    QMenu *menuH_hner_verwaltung;
    QMenu *menu_Legeleistung;
    QMenu *menu_F_tterung;
    QMenu *menu_Zucht;
    QMenu *menu_Krankenheit;
    QMenu *menu_Medikamentengabe;
    QMenu *menu_Pflege;
    QMenu *menu_Extras;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(966, 386);
        action_Sprache = new QAction(MainWindow);
        action_Sprache->setObjectName(QString::fromUtf8("action_Sprache"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lbname = new QLabel(centralwidget);
        lbname->setObjectName(QString::fromUtf8("lbname"));
        lbname->setGeometry(QRect(810, 80, 71, 16));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setBold(true);
        lbname->setFont(font);
        lbpic = new QLabel(centralwidget);
        lbpic->setObjectName(QString::fromUtf8("lbpic"));
        lbpic->setGeometry(QRect(590, 110, 301, 171));
        lbpic->setPixmap(QPixmap(QString::fromUtf8(":/img/image/chicken1.jpg")));
        lbtitle = new QLabel(centralwidget);
        lbtitle->setObjectName(QString::fromUtf8("lbtitle"));
        lbtitle->setGeometry(QRect(630, 60, 211, 16));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(12);
        font1.setBold(true);
        lbtitle->setFont(font1);
        lbtitle->setAlignment(Qt::AlignCenter);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(50, 50, 471, 221));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 40, 405, 135));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        rbRooster = new QRadioButton(layoutWidget);
        rbRooster->setObjectName(QString::fromUtf8("rbRooster"));
        rbRooster->setEnabled(true);
        rbRooster->setMinimumSize(QSize(100, 20));
        rbRooster->setMaximumSize(QSize(100, 20));

        horizontalLayout->addWidget(rbRooster);

        cboRooster = new QComboBox(layoutWidget);
        cboRooster->addItem(QString());
        cboRooster->addItem(QString());
        cboRooster->addItem(QString());
        cboRooster->addItem(QString());
        cboRooster->addItem(QString());
        cboRooster->addItem(QString());
        cboRooster->addItem(QString());
        cboRooster->addItem(QString());
        cboRooster->addItem(QString());
        cboRooster->addItem(QString());
        cboRooster->setObjectName(QString::fromUtf8("cboRooster"));
        cboRooster->setEnabled(false);
        cboRooster->setMinimumSize(QSize(150, 22));
        cboRooster->setMaximumSize(QSize(150, 22));

        horizontalLayout->addWidget(cboRooster);

        letRooster = new QLineEdit(layoutWidget);
        letRooster->setObjectName(QString::fromUtf8("letRooster"));
        letRooster->setEnabled(false);

        horizontalLayout->addWidget(letRooster);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        rbHen = new QRadioButton(layoutWidget);
        rbHen->setObjectName(QString::fromUtf8("rbHen"));
        rbHen->setMinimumSize(QSize(100, 20));
        rbHen->setMaximumSize(QSize(100, 20));

        horizontalLayout_2->addWidget(rbHen);

        cboHen = new QComboBox(layoutWidget);
        cboHen->addItem(QString());
        cboHen->addItem(QString());
        cboHen->addItem(QString());
        cboHen->addItem(QString());
        cboHen->addItem(QString());
        cboHen->addItem(QString());
        cboHen->addItem(QString());
        cboHen->addItem(QString());
        cboHen->addItem(QString());
        cboHen->addItem(QString());
        cboHen->addItem(QString());
        cboHen->setObjectName(QString::fromUtf8("cboHen"));
        cboHen->setEnabled(false);
        cboHen->setMinimumSize(QSize(150, 22));
        cboHen->setMaximumSize(QSize(150, 22));

        horizontalLayout_2->addWidget(cboHen);

        leHen = new QLineEdit(layoutWidget);
        leHen->setObjectName(QString::fromUtf8("leHen"));
        leHen->setEnabled(false);

        horizontalLayout_2->addWidget(leHen);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        rbEgg = new QRadioButton(layoutWidget);
        rbEgg->setObjectName(QString::fromUtf8("rbEgg"));
        rbEgg->setMinimumSize(QSize(100, 20));
        rbEgg->setMaximumSize(QSize(100, 20));

        horizontalLayout_3->addWidget(rbEgg);

        cboEgg = new QComboBox(layoutWidget);
        cboEgg->addItem(QString());
        cboEgg->addItem(QString());
        cboEgg->addItem(QString());
        cboEgg->addItem(QString());
        cboEgg->addItem(QString());
        cboEgg->addItem(QString());
        cboEgg->addItem(QString());
        cboEgg->setObjectName(QString::fromUtf8("cboEgg"));
        cboEgg->setEnabled(false);
        cboEgg->setMinimumSize(QSize(150, 22));
        cboEgg->setMaximumSize(QSize(150, 22));

        horizontalLayout_3->addWidget(cboEgg);

        letEgg = new QLineEdit(layoutWidget);
        letEgg->setObjectName(QString::fromUtf8("letEgg"));
        letEgg->setEnabled(false);

        horizontalLayout_3->addWidget(letEgg);


        verticalLayout->addLayout(horizontalLayout_3);

        btnSearch = new QPushButton(groupBox);
        btnSearch->setObjectName(QString::fromUtf8("btnSearch"));
        btnSearch->setGeometry(QRect(380, 180, 75, 24));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(550, 30, 371, 301));
        tableView->setSortingEnabled(true);
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(50, 280, 471, 27));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        btncfgRooster = new QPushButton(layoutWidget1);
        btncfgRooster->setObjectName(QString::fromUtf8("btncfgRooster"));
        btncfgRooster->setMinimumSize(QSize(100, 25));
        btncfgRooster->setMaximumSize(QSize(100, 25));

        horizontalLayout_4->addWidget(btncfgRooster);

        btncfgHen = new QPushButton(layoutWidget1);
        btncfgHen->setObjectName(QString::fromUtf8("btncfgHen"));
        btncfgHen->setMinimumSize(QSize(100, 25));
        btncfgHen->setMaximumSize(QSize(100, 25));

        horizontalLayout_4->addWidget(btncfgHen);

        btncfgEgg = new QPushButton(layoutWidget1);
        btncfgEgg->setObjectName(QString::fromUtf8("btncfgEgg"));
        btncfgEgg->setMinimumSize(QSize(100, 25));
        btncfgEgg->setMaximumSize(QSize(100, 25));

        horizontalLayout_4->addWidget(btncfgEgg);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        btnClose = new QPushButton(layoutWidget1);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));

        horizontalLayout_4->addWidget(btnClose);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 966, 22));
        menuH_hner_verwaltung = new QMenu(menubar);
        menuH_hner_verwaltung->setObjectName(QString::fromUtf8("menuH_hner_verwaltung"));
        menu_Legeleistung = new QMenu(menubar);
        menu_Legeleistung->setObjectName(QString::fromUtf8("menu_Legeleistung"));
        menu_F_tterung = new QMenu(menubar);
        menu_F_tterung->setObjectName(QString::fromUtf8("menu_F_tterung"));
        menu_Zucht = new QMenu(menubar);
        menu_Zucht->setObjectName(QString::fromUtf8("menu_Zucht"));
        menu_Krankenheit = new QMenu(menubar);
        menu_Krankenheit->setObjectName(QString::fromUtf8("menu_Krankenheit"));
        menu_Medikamentengabe = new QMenu(menubar);
        menu_Medikamentengabe->setObjectName(QString::fromUtf8("menu_Medikamentengabe"));
        menu_Pflege = new QMenu(menubar);
        menu_Pflege->setObjectName(QString::fromUtf8("menu_Pflege"));
        menu_Extras = new QMenu(menubar);
        menu_Extras->setObjectName(QString::fromUtf8("menu_Extras"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuH_hner_verwaltung->menuAction());
        menubar->addAction(menu_Legeleistung->menuAction());
        menubar->addAction(menu_F_tterung->menuAction());
        menubar->addAction(menu_Zucht->menuAction());
        menubar->addAction(menu_Krankenheit->menuAction());
        menubar->addAction(menu_Medikamentengabe->menuAction());
        menubar->addAction(menu_Pflege->menuAction());
        menubar->addAction(menu_Extras->menuAction());
        menu_Extras->addAction(action_Sprache);

        retranslateUi(MainWindow);
        QObject::connect(btnClose, &QPushButton::clicked, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action_Sprache->setText(QCoreApplication::translate("MainWindow", "&Sprache", nullptr));
        lbname->setText(QCoreApplication::translate("MainWindow", "Fuhao Guo", nullptr));
        lbpic->setText(QString());
        lbtitle->setText(QCoreApplication::translate("MainWindow", "Chicken Management V1.0", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Suchen", nullptr));
        rbRooster->setText(QCoreApplication::translate("MainWindow", "Hahn", nullptr));
        cboRooster->setItemText(0, QCoreApplication::translate("MainWindow", "ID", nullptr));
        cboRooster->setItemText(1, QCoreApplication::translate("MainWindow", "Name", nullptr));
        cboRooster->setItemText(2, QCoreApplication::translate("MainWindow", "Breed", nullptr));
        cboRooster->setItemText(3, QCoreApplication::translate("MainWindow", "HatchingDate", nullptr));
        cboRooster->setItemText(4, QCoreApplication::translate("MainWindow", "TrunkSize", nullptr));
        cboRooster->setItemText(5, QCoreApplication::translate("MainWindow", "FeatherColor", nullptr));
        cboRooster->setItemText(6, QCoreApplication::translate("MainWindow", "CombColor", nullptr));
        cboRooster->setItemText(7, QCoreApplication::translate("MainWindow", "Weight", nullptr));
        cboRooster->setItemText(8, QCoreApplication::translate("MainWindow", "Comatibility", nullptr));
        cboRooster->setItemText(9, QCoreApplication::translate("MainWindow", "FertilizationRate", nullptr));

        rbHen->setText(QCoreApplication::translate("MainWindow", "Henne", nullptr));
        cboHen->setItemText(0, QCoreApplication::translate("MainWindow", "ID", nullptr));
        cboHen->setItemText(1, QCoreApplication::translate("MainWindow", "Name", nullptr));
        cboHen->setItemText(2, QCoreApplication::translate("MainWindow", "Breed", nullptr));
        cboHen->setItemText(3, QCoreApplication::translate("MainWindow", "HatchingDate", nullptr));
        cboHen->setItemText(4, QCoreApplication::translate("MainWindow", "EggColor", nullptr));
        cboHen->setItemText(5, QCoreApplication::translate("MainWindow", "AverageEggWeight", nullptr));
        cboHen->setItemText(6, QCoreApplication::translate("MainWindow", "TrunkSize", nullptr));
        cboHen->setItemText(7, QCoreApplication::translate("MainWindow", "FeatherColor", nullptr));
        cboHen->setItemText(8, QCoreApplication::translate("MainWindow", "CombColor", nullptr));
        cboHen->setItemText(9, QCoreApplication::translate("MainWindow", "Weight", nullptr));
        cboHen->setItemText(10, QCoreApplication::translate("MainWindow", "Compatibility", nullptr));

        rbEgg->setText(QCoreApplication::translate("MainWindow", "Ei", nullptr));
        cboEgg->setItemText(0, QCoreApplication::translate("MainWindow", "ID", nullptr));
        cboEgg->setItemText(1, QCoreApplication::translate("MainWindow", "HenID", nullptr));
        cboEgg->setItemText(2, QCoreApplication::translate("MainWindow", "RoosterID", nullptr));
        cboEgg->setItemText(3, QCoreApplication::translate("MainWindow", "DataLaid", nullptr));
        cboEgg->setItemText(4, QCoreApplication::translate("MainWindow", "Weight", nullptr));
        cboEgg->setItemText(5, QCoreApplication::translate("MainWindow", "CoopNumber", nullptr));
        cboEgg->setItemText(6, QCoreApplication::translate("MainWindow", "Fertilized", nullptr));

        btnSearch->setText(QCoreApplication::translate("MainWindow", "Suchen", nullptr));
        btncfgRooster->setText(QCoreApplication::translate("MainWindow", "Config Hahn", nullptr));
        btncfgHen->setText(QCoreApplication::translate("MainWindow", "Config Henne", nullptr));
        btncfgEgg->setText(QCoreApplication::translate("MainWindow", "Config Ei", nullptr));
        btnClose->setText(QCoreApplication::translate("MainWindow", "Schlie\303\237en", nullptr));
        menuH_hner_verwaltung->setTitle(QCoreApplication::translate("MainWindow", "H\303\274hner&verwaltung", nullptr));
        menu_Legeleistung->setTitle(QCoreApplication::translate("MainWindow", "&Legeleistung", nullptr));
        menu_F_tterung->setTitle(QCoreApplication::translate("MainWindow", "&F\303\274tterung", nullptr));
        menu_Zucht->setTitle(QCoreApplication::translate("MainWindow", "&Zucht", nullptr));
        menu_Krankenheit->setTitle(QCoreApplication::translate("MainWindow", "&Krankenheit", nullptr));
        menu_Medikamentengabe->setTitle(QCoreApplication::translate("MainWindow", "&Medikamentengabe", nullptr));
        menu_Pflege->setTitle(QCoreApplication::translate("MainWindow", "&Pflege", nullptr));
        menu_Extras->setTitle(QCoreApplication::translate("MainWindow", "&Extras", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

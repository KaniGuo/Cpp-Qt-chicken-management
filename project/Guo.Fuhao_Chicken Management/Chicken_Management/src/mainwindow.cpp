#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hendialog.h"
#include "eggdialog.h"
#include "roosterdialog.h"
#include "sprachedialog.h"

#include <QApplication>
#include <QWidget>
#include <QTimer>
#include <QLabel>

#include <QFile>
#include <QTextStream>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setVisible(false);

    QTimer::singleShot(3000, [this]() {
            ui->lbname->close();
            ui->lbpic->close();
            ui->lbtitle->close();
        });

    QString connectionString ="Driver={SQL Server};"
                            "Server=RZPC-4005;"
                            "Database=chicken_management;"
                            "Trusted_Connection=Yes";
    qDebug() << connectionString;

    db = QSqlDatabase::addDatabase("QODBC");
    db.setConnectOptions();
    db.setDatabaseName(connectionString);
    if(!db.open())
    {
        qDebug() << db.lastError().text();
        return;
    }
    qDebug() << "Datenbank is open";

    setWindowTitle("Chicken Management");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btncfgRooster_clicked()
{
//    query = new QSqlQuery(db);
//    QString sqlStatement = "select * from Rooster";
    RoosterDialog *roosterdialog = new RoosterDialog;
    roosterdialog->exec();
}


void MainWindow::on_btncfgHen_clicked()
{
//    query = new QSqlQuery(db);
//    QString sqlStatement = "select * from Hen";
    HenDialog *hendialog = new HenDialog;
    hendialog->exec();
}


void MainWindow::on_btncfgEgg_clicked()
{
    EggDialog *eggdialog = new EggDialog;
    eggdialog->exec();
}


void MainWindow::on_rbRooster_clicked()
{
    ui->cboRooster->setEnabled(true);
    ui->letRooster->setEnabled(true);

    ui->cboHen->setEnabled(false);
    ui->leHen->setEnabled(false);

    ui->cboEgg->setEnabled(false);
    ui->letEgg->setEnabled(false);
}


void MainWindow::on_rbHen_clicked()
{
    ui->cboHen->setEnabled(true);
    ui->leHen->setEnabled(true);

    ui->cboRooster->setEnabled(false);
    ui->letRooster->setEnabled(false);

    ui->cboEgg->setEnabled(false);
    ui->letEgg->setEnabled(false);
}


void MainWindow::on_rbEgg_clicked()
{
    ui->cboEgg->setEnabled(true);
    ui->letEgg->setEnabled(true);

    ui->cboRooster->setEnabled(false);
    ui->letRooster->setEnabled(false);

    ui->cboHen->setEnabled(false);
    ui->leHen->setEnabled(false);

}


void MainWindow::on_btnSearch_clicked()
{
    ui->tableView->setVisible(true);
    query = new QSqlQuery(db);
    if (ui->rbRooster->isChecked()){
        qDebug() << "Rooster";


        model = new QStandardItemModel(0, 10, this);
        model->setHorizontalHeaderItem(0, new QStandardItem("Rooster_ID"));
        model->setHorizontalHeaderItem(1, new QStandardItem("Name"));
        model->setHorizontalHeaderItem(2, new QStandardItem("Breed"));
        model->setHorizontalHeaderItem(3, new QStandardItem("HatchingDate"));
        model->setHorizontalHeaderItem(4, new QStandardItem("TrunkSize"));
        model->setHorizontalHeaderItem(5, new QStandardItem("FeatherColor"));
        model->setHorizontalHeaderItem(6, new QStandardItem("CombColor"));
        model->setHorizontalHeaderItem(7, new QStandardItem("Weight(kg)"));
        model->setHorizontalHeaderItem(8, new QStandardItem("Compatibility"));
        model->setHorizontalHeaderItem(9, new QStandardItem("FertilizationRate"));

        ui->tableView->setModel(model);

        QString selectedFeature = ui->cboRooster->currentText();
        QString searchValue = ui->letRooster->text();

        searchValue = "%" + searchValue + "%";
        QString queryStr = QString("SELECT * FROM Rooster WHERE Rooster_%1 LIKE :searchValue").arg(selectedFeature);


        query->prepare(queryStr);
        query->bindValue(":searchValue", searchValue);

        if (!query->exec()) {
          QMessageBox::critical(this, tr("Zugriffsfehler"),
                                tr("Es konnte nicht lesend auf die"
                                " Datenbank zugegriffen werden"));
          delete query;
          return;
        }

        row = 0;

        QStandardItem *col0;
        QStandardItem *col1;
        QStandardItem *col2;
        QStandardItem *col3;
        QStandardItem *col4;
        QStandardItem *col5;
        QStandardItem *col6;
        QStandardItem *col7;
        QStandardItem *col8;
        QStandardItem *col9;

        while (query->next()) {

          col0 = new QStandardItem;
          col0->setText(query->value("Rooster_ID").toString());
          model->setItem(row, 0, col0);

          col1 = new QStandardItem;
          col1->setText(query->value("Rooster_Name").toString());
          model->setItem(row, 1, col1);

          col2 = new QStandardItem;
          col2->setText(query->value("Rooster_Breed").toString());
          model->setItem(row, 2, col2);

          col3 = new QStandardItem;
          col3->setText(query->value("Rooster_HatchingDate").toString());
          model->setItem(row, 3, col3);

          col4 = new QStandardItem;
          col4->setText(query->value("Rooster_TrunkSize").toString());
          model->setItem(row, 4, col4);

          col5 = new QStandardItem;
          col5->setText(query->value("Rooster_FeatherColor").toString());
          model->setItem(row, 5, col5);

          col6 = new QStandardItem;
          col6->setText(query->value("Rooster_CombColor").toString());
          model->setItem(row, 6, col6);

          col7 = new QStandardItem;
          col7->setText(query->value("Rooster_Weight").toString());
          model->setItem(row, 7, col7);

          col8 = new QStandardItem;
          col8->setText(query->value("Rooster_Compatibility").toString());
          model->setItem(row, 8, col8);

          col9 = new QStandardItem;
          col9->setText(query->value("Rooster_FertilizationRate").toString());
          model->setItem(row, 9, col9);
          row++;
        }


    }else if(ui->rbHen->isChecked()){
        QString sqlStatement = "select * from Hen";
        query->exec(sqlStatement);
        qDebug() << "Hen";

        model = new QStandardItemModel(0, 12, this);
        model->setHorizontalHeaderItem(0, new QStandardItem("Hen_ID"));
        model->setHorizontalHeaderItem(1, new QStandardItem("Name"));
        model->setHorizontalHeaderItem(2, new QStandardItem("Breed"));
        model->setHorizontalHeaderItem(3, new QStandardItem("HatchingDate"));
        model->setHorizontalHeaderItem(4, new QStandardItem("EggColor"));
        model->setHorizontalHeaderItem(5, new QStandardItem("AverageEggWeight(g)"));
        model->setHorizontalHeaderItem(6, new QStandardItem("TrunkSize"));
        model->setHorizontalHeaderItem(7, new QStandardItem("FeatherColor"));
        model->setHorizontalHeaderItem(8, new QStandardItem("CombColor"));
        model->setHorizontalHeaderItem(9, new QStandardItem("Weight(kg)"));
        model->setHorizontalHeaderItem(10, new QStandardItem("Compatibility"));
        model->setHorizontalHeaderItem(11, new QStandardItem("Legeleistung"));

        ui->tableView->setModel(model);

        QString selectedFeature = ui->cboHen->currentText();
        QString searchValue = ui->leHen->text();

        searchValue = "%" + searchValue + "%";
        QString queryStr = QString("SELECT * FROM Hen WHERE Hen_%1 LIKE :searchValue").arg(selectedFeature);


        query->prepare(queryStr);
        query->bindValue(":searchValue", searchValue);

        if (!query->exec()) {
            QMessageBox::critical(this, tr("Zugriffsfehler"),
                                  tr("Es konnte nicht lesend auf die"
                                  " Datenbank zugegriffen werden"));
          delete query;
          return;
        }

        row = 0;

        QStandardItem *col0;
        QStandardItem *col1;
        QStandardItem *col2;
        QStandardItem *col3;
        QStandardItem *col4;
        QStandardItem *col5;
        QStandardItem *col6;
        QStandardItem *col7;
        QStandardItem *col8;
        QStandardItem *col9;
        QStandardItem *col10;
        QStandardItem *col11;

        while (query->next()) {

          col0 = new QStandardItem;
          col0->setText(query->value("Hen_ID").toString());
          model->setItem(row, 0, col0);

          col1 = new QStandardItem;
          col1->setText(query->value("Hen_Name").toString());
          model->setItem(row, 1, col1);

          col2 = new QStandardItem;
          col2->setText(query->value("Hen_Breed").toString());
          model->setItem(row, 2, col2);

          col3 = new QStandardItem;
          col3->setText(query->value("Hen_HatchingDate").toString());
          model->setItem(row, 3, col3);

          col4 = new QStandardItem;
          col4->setText(query->value("Hen_EggColor").toString());
          model->setItem(row, 4, col4);

          col5 = new QStandardItem;
          col5->setText(query->value("Hen_AverageEggWeight").toString());
          model->setItem(row, 5, col5);

          col6 = new QStandardItem;
          col6->setText(query->value("Hen_TrunkSize").toString());
          model->setItem(row, 6, col6);

          col7 = new QStandardItem;
          col7->setText(query->value("Hen_FeatherColor").toString());
          model->setItem(row, 7, col7);

          col8 = new QStandardItem;
          col8->setText(query->value("Hen_CombColor").toString());
          model->setItem(row, 8, col8);

          col9 = new QStandardItem;
          col9->setText(query->value("Hen_Weight").toString());
          model->setItem(row, 9, col9);

          col10 = new QStandardItem;
          col10->setText(query->value("Hen_Compatibility").toString());
          model->setItem(row, 10, col10);

          col11 = new QStandardItem;
          col11->setText(query->value("Hen_Legeleistung").toString());
          model->setItem(row, 11, col11);
          row++;
        }

    }else if(ui->rbEgg->isChecked()){
        QString sqlStatement = "select * from Egg";
        query->exec(sqlStatement);

        qDebug() << "Egg";

        model = new QStandardItemModel(0, 7, this);
        model->setHorizontalHeaderItem(0, new QStandardItem("Egg_ID"));
        model->setHorizontalHeaderItem(1, new QStandardItem("HenID"));
        model->setHorizontalHeaderItem(2, new QStandardItem("RoosterID"));
        model->setHorizontalHeaderItem(3, new QStandardItem("DateLaid"));
        model->setHorizontalHeaderItem(4, new QStandardItem("Weight(g)"));
        model->setHorizontalHeaderItem(5, new QStandardItem("CoopNumber"));
        model->setHorizontalHeaderItem(6, new QStandardItem("Fertilized"));

        ui->tableView->setModel(model);

        QString selectedFeature = ui->cboEgg->currentText();
        QString searchValue = ui->letEgg->text();

        searchValue = "%" + searchValue + "%";
        QString queryStr = QString("SELECT * FROM Egg WHERE Egg_%1 LIKE :searchValue").arg(selectedFeature);


        query->prepare(queryStr);
        query->bindValue(":searchValue", searchValue);

        if (!query->exec()) {
            QMessageBox::critical(this, tr("Zugriffsfehler"),
                                  tr("Es konnte nicht lesend auf die"
                                  " Datenbank zugegriffen werden"));
            delete query;
            return;
        }

        row = 0;

        QStandardItem *col0;
        QStandardItem *col1;
        QStandardItem *col2;
        QStandardItem *col3;
        QStandardItem *col4;
        QStandardItem *col5;
        QStandardItem *col6;

        while (query->next()) {
            col0 = new QStandardItem;
            col0->setText(query->value("Egg_ID").toString());
            model->setItem(row, 0, col0);

            col1 = new QStandardItem;
            col1->setText(query->value("Egg_HenID").toString());
            model->setItem(row, 1, col1);

            col2 = new QStandardItem;
            col2->setText(query->value("Egg_RoosterID").toString());
            model->setItem(row, 2, col2);

            col3 = new QStandardItem;
            col3->setText(query->value("Egg_DateLaid").toString());
            model->setItem(row, 3, col3);

            col4 = new QStandardItem;
            col4->setText(query->value("Egg_Weight").toString());
            model->setItem(row, 4, col4);

            col5 = new QStandardItem;
            col5->setText(query->value("Egg_CoopNumber").toString());
            model->setItem(row, 5, col5);

            col6 = new QStandardItem;
            col6->setText(query->value("Egg_Fertilized").toString());
            model->setItem(row, 6, col6);

            row++;
        }
    }

    delete query;
}

void MainWindow::on_action_Sprache_triggered()
{
    SpracheDialog *sprachedialog = new SpracheDialog;
    sprachedialog->exec();
}


#include "hendialog.h"
#include "ui_hendialog.h"

HenDialog::HenDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HenDialog)
{
    ui->setupUi(this);

    init();
    dbOpen();
    dbRead();
}

HenDialog::~HenDialog()
{
    delete ui;
}

void HenDialog::init()
{

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
}

void HenDialog::dbOpen()
{
    QString connectionString = "Driver={SQL Server};Server=RZPC-4005;"
                               "Database=chicken_management;Trusted_Connection=Yes";

    dBase = QSqlDatabase::addDatabase("QODBC");
    dBase.setConnectOptions();
    dBase.setDatabaseName(connectionString);

    if (!dBase.open()) {
      QMessageBox::critical(this, tr("Kein Datenbankzugriff"),
                            tr("Zugriff auf die Datenbank fehlgeschlagen!"));
      return;
    }
}

void HenDialog::dbRead()
{
    dbQuery = new QSqlQuery(dBase);
    if (!dbQuery->exec("select * from Hen;")) {
      QMessageBox::critical(this, tr("Zugriffsfehler"),
                            tr("Es konnte nicht lesend auf die"
                            " Datenbank zugegriffen werden"));
      delete dbQuery;
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

    while (dbQuery->next()) {

      col0 = new QStandardItem;
      col0->setText(dbQuery->value("Hen_ID").toString());
      model->setItem(row, 0, col0);

      col1 = new QStandardItem;
      col1->setText(dbQuery->value("Hen_Name").toString());
      model->setItem(row, 1, col1);

      col2 = new QStandardItem;
      col2->setText(dbQuery->value("Hen_Breed").toString());
      model->setItem(row, 2, col2);

      col3 = new QStandardItem;
      col3->setText(dbQuery->value("Hen_HatchingDate").toString());
      model->setItem(row, 3, col3);

      col4 = new QStandardItem;
      col4->setText(dbQuery->value("Hen_EggColor").toString());
      model->setItem(row, 4, col4);

      col5 = new QStandardItem;
      col5->setText(dbQuery->value("Hen_AverageEggWeight").toString());
      model->setItem(row, 5, col5);

      col6 = new QStandardItem;
      col6->setText(dbQuery->value("Hen_TrunkSize").toString());
      model->setItem(row, 6, col6);

      col7 = new QStandardItem;
      col7->setText(dbQuery->value("Hen_FeatherColor").toString());
      model->setItem(row, 7, col7);

      col8 = new QStandardItem;
      col8->setText(dbQuery->value("Hen_CombColor").toString());
      model->setItem(row, 8, col8);

      col9 = new QStandardItem;
      col9->setText(dbQuery->value("Hen_Weight").toString());
      model->setItem(row, 9, col9);

      col10 = new QStandardItem;
      col10->setText(dbQuery->value("Hen_Compatibility").toString());
      model->setItem(row, 10, col10);

      col11 = new QStandardItem;
      col11->setText(dbQuery->value("Hen_Legeleistung").toString());
      model->setItem(row, 11, col11);
      row++;
    }

    delete dbQuery;
}

void HenDialog::on_btnAddNew_clicked()
{
    row = model->rowCount();
    model->insertRow(row);

    idx = model->index(row, 0);

    ui->tableView->setCurrentIndex(idx);
    ui->tableView->edit(idx);
}


void HenDialog::on_btnInsert_clicked()
{
    model->insertRow(ui->tableView->currentIndex().row());

    idx = model->index(row, 0);

    ui->tableView->setCurrentIndex(idx);
    ui->tableView->edit(idx);
}

void HenDialog::saveToDatabase()
{
    QSqlQuery deleteQuery(dBase);
    deleteQuery.prepare("DELETE FROM Hen");
    if (!deleteQuery.exec()) {
        QMessageBox::critical(this, tr("Datenbankfehler"),
                              tr("Daten konnten nicht aus der Hen-Tabelle gelöscht werden"));
        return;
    }

    int rows = model->rowCount();
//    int columns = model->columnCount();

    QSqlQuery query(dBase);

    query.prepare("INSERT INTO Hen (Hen_ID, "
                  "Hen_Name, "
                  "Hen_Breed, "
                  "Hen_HatchingDate, "
                  "Hen_EggColor, "
                  "Hen_AverageEggWeight, "
                  "Hen_TrunkSize, "
                  "Hen_FeatherColor, "
                  "Hen_CombColor, "
                  "Hen_Weight, "
                  "Hen_Compatibility,"
                  "Hen_Legeleistung) "
                  "VALUES (:id, "
                  ":name, "
                  ":breed, "
                  ":hatchingdate,"
                  ":eggcolor, "
                  ":averageeggweight, "
                  ":trunksize, "
                  ":feathercolor, "
                  ":combcolor, "
                  ":weight, "
                  ":compatibility, "
                  ":legeleistung)");

    for (int row = 0; row < rows; ++row) {
        query.bindValue(":id", model->index(row, 0).data());
        query.bindValue(":name", model->index(row, 1).data());
        query.bindValue(":breed", model->index(row, 2).data());
        query.bindValue(":hatchingdate", model->index(row, 3).data());
        query.bindValue(":eggcolor", model->index(row, 4).data());
        query.bindValue(":averageeggweight", model->index(row, 5).data());
        query.bindValue(":trunksize", model->index(row, 6).data());
        query.bindValue(":feathercolor", model->index(row, 7).data());
        query.bindValue(":combcolor", model->index(row, 8).data());
        query.bindValue(":weight", model->index(row, 9).data());
        query.bindValue(":compatibility", model->index(row, 10).data());
        query.bindValue(":legeleistung", model->index(row, 11).data());

        if (!query.exec()) {
            QMessageBox::critical(this, tr("Datenbankfehler"),
                                  tr("Daten konnten nicht in der Hen-Tabelle gespeichert werden"));
            return;
        }
    }

    QMessageBox::information(this, tr("Erfolg"), tr("Daten werden in der Hen-Tabelle gespeichert"));
}

void HenDialog::on_btnSave_clicked()
{
    int ret = QMessageBox::question(this, tr("In Datenbank speichern"),
                                    tr("Möchten Sie die Änderungen in der Datenbank speichern?"),
                                    QMessageBox::Yes | QMessageBox::No);

       if (ret == QMessageBox::Yes) {
           saveToDatabase();
       }
}


void HenDialog::on_btnDelete_clicked()
{
    row = ui->tableView->currentIndex().row();
    model->removeRow(row);
}




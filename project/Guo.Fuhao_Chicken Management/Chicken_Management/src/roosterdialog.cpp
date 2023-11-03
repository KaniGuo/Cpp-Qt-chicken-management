#include "roosterdialog.h"
#include "ui_roosterdialog.h"

RoosterDialog::RoosterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RoosterDialog)
{
    ui->setupUi(this);

    init();
    dbOpen();
    dbRead();
}

RoosterDialog::~RoosterDialog()
{
    delete ui;
}

void RoosterDialog::init()
{

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
}

void RoosterDialog::dbOpen()
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

void RoosterDialog::dbRead()
{
    dbQuery = new QSqlQuery(dBase);
    if (!dbQuery->exec("select * from Rooster;")) {
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

    while (dbQuery->next()) {

      col0 = new QStandardItem;
      col0->setText(dbQuery->value("Rooster_ID").toString());
      model->setItem(row, 0, col0);

      col1 = new QStandardItem;
      col1->setText(dbQuery->value("Rooster_Name").toString());
      model->setItem(row, 1, col1);

      col2 = new QStandardItem;
      col2->setText(dbQuery->value("Rooster_Breed").toString());
      model->setItem(row, 2, col2);

      col3 = new QStandardItem;
      col3->setText(dbQuery->value("Rooster_HatchingDate").toString());
      model->setItem(row, 3, col3);

      col4 = new QStandardItem;
      col4->setText(dbQuery->value("Rooster_TrunkSize").toString());
      model->setItem(row, 4, col4);

      col5 = new QStandardItem;
      col5->setText(dbQuery->value("Rooster_FeatherColor").toString());
      model->setItem(row, 5, col5);

      col6 = new QStandardItem;
      col6->setText(dbQuery->value("Rooster_CombColor").toString());
      model->setItem(row, 6, col6);

      col7 = new QStandardItem;
      col7->setText(dbQuery->value("Rooster_Weight").toString());
      model->setItem(row, 7, col7);

      col8 = new QStandardItem;
      col8->setText(dbQuery->value("Rooster_Compatibility").toString());
      model->setItem(row, 8, col8);

      col9 = new QStandardItem;
      col9->setText(dbQuery->value("Rooster_FertilizationRate").toString());
      model->setItem(row, 9, col9);
      row++;
    }

    delete dbQuery;
}


void RoosterDialog::on_btnAddNew_clicked()
{
    row = model->rowCount();
    model->insertRow(row);

    idx = model->index(row, 0);

    ui->tableView->setCurrentIndex(idx);
    ui->tableView->edit(idx);
}

void RoosterDialog::on_btnInsert_clicked()
{
    model->insertRow(ui->tableView->currentIndex().row());

    idx = model->index(row, 0);

    ui->tableView->setCurrentIndex(idx);
    ui->tableView->edit(idx);
}

void RoosterDialog::on_btnDelete_clicked()
{
    row = ui->tableView->currentIndex().row();
    model->removeRow(row);
}

void RoosterDialog::saveToDatabase()
{
    QSqlQuery deleteQuery(dBase);
    deleteQuery.prepare("DELETE FROM Rooster");
    if (!deleteQuery.exec()) {
        QMessageBox::critical(this, tr("Datenbankfehler"),
                              tr("Daten konnten nicht aus der Rooster-Tabelle gelöscht werden"));
        return;
    }

    int rows = model->rowCount();
//    int columns = model->columnCount();

    QSqlQuery query(dBase);

    query.prepare("INSERT INTO Rooster (Rooster_ID, Rooster_Name, Rooster_Breed, Rooster_HatchingDate, Rooster_TrunkSize, Rooster_FeatherColor, Rooster_CombColor, Rooster_Weight, Rooster_Compatibility, Rooster_FertilizationRate) "
                  "VALUES (:id, :name, :breed, :hatchingDate, :trunkSize, :featherColor, :combColor, :weight, :compatibility, :fertilizationRate)");

    for (int row = 0; row < rows; ++row) {
        query.bindValue(":id", model->index(row, 0).data());
        query.bindValue(":name", model->index(row, 1).data());
        query.bindValue(":breed", model->index(row, 2).data());
        query.bindValue(":hatchingDate", model->index(row, 3).data());
        query.bindValue(":trunkSize", model->index(row, 4).data());
        query.bindValue(":featherColor", model->index(row, 5).data());
        query.bindValue(":combColor", model->index(row, 6).data());
        query.bindValue(":weight", model->index(row, 7).data());
        query.bindValue(":compatibility", model->index(row, 8).data());
        query.bindValue(":fertilizationRate", model->index(row, 9).data());

        if (!query.exec()) {
            QMessageBox::critical(this, tr("Datenbankfehler"),
                                  tr("Daten konnten nicht in der Rooster-Tabelle gespeichert werden"));
            return;
        }
    }

    QMessageBox::information(this, tr("Erfolg"), tr("Daten werden in der Rooster-Tabelle gespeichert"));
}

void RoosterDialog::on_btnSave_clicked()
{
    int ret = QMessageBox::question(this, tr("In Datenbank speichern"),
                                    tr("Möchten Sie die Änderungen in der Datenbank speichern?"),
                                    QMessageBox::Yes | QMessageBox::No);

       if (ret == QMessageBox::Yes) {
           saveToDatabase();
       }
}


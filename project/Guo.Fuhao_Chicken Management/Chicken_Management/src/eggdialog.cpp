#include "eggdialog.h"
#include "ui_eggdialog.h"

EggDialog::EggDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EggDialog)
{
    ui->setupUi(this);

    init();
    dbOpen();
    dbRead();
}

EggDialog::~EggDialog()
{
    delete ui;
}

void EggDialog::init()
{

    model = new QStandardItemModel(0, 7, this);
    model->setHorizontalHeaderItem(0, new QStandardItem("Egg_ID"));
    model->setHorizontalHeaderItem(1, new QStandardItem("HenID"));
    model->setHorizontalHeaderItem(2, new QStandardItem("RoosterID"));
    model->setHorizontalHeaderItem(3, new QStandardItem("DateLaid"));
    model->setHorizontalHeaderItem(4, new QStandardItem("Weight(g)"));
    model->setHorizontalHeaderItem(5, new QStandardItem("CoopNumber"));
    model->setHorizontalHeaderItem(6, new QStandardItem("Fertilized"));

    ui->tableView->setModel(model);

}

void EggDialog::dbOpen()
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

void EggDialog::dbRead()
{
    dbQuery = new QSqlQuery(dBase);
    if (!dbQuery->exec("select * from Egg;")) {
        QMessageBox::critical(this, tr("Zugriffsfehler"),
                              tr("Es konnte nicht lesend auf die "
                              "Datenbank zugegriffen werden"));
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

    while (dbQuery->next()) {
        col0 = new QStandardItem;
        col0->setText(dbQuery->value("Egg_ID").toString());
        model->setItem(row, 0, col0);

        col1 = new QStandardItem;
        col1->setText(dbQuery->value("Egg_HenID").toString());
        model->setItem(row, 1, col1);

        col2 = new QStandardItem;
        col2->setText(dbQuery->value("Egg_RoosterID").toString());
        model->setItem(row, 2, col2);

        col3 = new QStandardItem;
        col3->setText(dbQuery->value("Egg_DateLaid").toString());
        model->setItem(row, 3, col3);

        col4 = new QStandardItem;
        col4->setText(dbQuery->value("Egg_Weight").toString());
        model->setItem(row, 4, col4);

        col5 = new QStandardItem;
        col5->setText(dbQuery->value("Egg_CoopNumber").toString());
        model->setItem(row, 5, col5);

        col6 = new QStandardItem;
        col6->setText(dbQuery->value("Egg_Fertilized").toString());
        model->setItem(row, 6, col6);

        row++;
    }

    delete dbQuery;

}

void EggDialog::on_btnAddNew_clicked()
{
    row = model->rowCount();
    model->insertRow(row);

    idx = model->index(row, 0);

    ui->tableView->setCurrentIndex(idx);
    ui->tableView->edit(idx);
}


void EggDialog::on_btnInsert_clicked()
{
    model->insertRow(ui->tableView->currentIndex().row());

    idx = model->index(row, 0);

    ui->tableView->setCurrentIndex(idx);
    ui->tableView->edit(idx);
}

void EggDialog::saveToDatabase()
{

    QSqlQuery deleteQuery(dBase);
    deleteQuery.prepare("DELETE FROM Egg");
    if (!deleteQuery.exec()) {
        QMessageBox::critical(this, tr("Datenbankfehler"),
                              tr("Daten konnten nicht aus der Egg-Tabelle gelöscht werden"));
        return;
    }

    int rows = model->rowCount();

    QSqlQuery query(dBase);

    query.prepare("INSERT INTO Egg (Egg_ID, "
                  "Egg_HenID, "
                  "Egg_RoosterID, "
                  "Egg_DateLaid, "
                  "Egg_Weight, "
                  "Egg_CoopNumber,"
                  "Egg_Fertilized) "
                  "VALUES (:id, "
                  ":henID, "
                  ":roosterID, "
                  ":dateLaid,"
                  ":weight, "
                  ":coopNumber,"
                  ":fertilized)");

    for (int row = 0; row < rows; ++row) {
        query.bindValue(":id", model->index(row, 0).data());
        query.bindValue(":henID", model->index(row, 1).data());
        query.bindValue(":roosterID", model->index(row, 2).data());
        query.bindValue(":dateLaid", model->index(row, 3).data());
        query.bindValue(":weight", model->index(row, 4).data());
        query.bindValue(":coopNumber", model->index(row, 5).data());
        query.bindValue(":fertilized", model->index(row, 6).data());

        if (!query.exec()) {
            QMessageBox::critical(this, tr("Datenbankfehler"),
                                  tr("Daten konnten nicht in der Egg-Tabelle gespeichert werden"));
            return;
        }
    }

    QMessageBox::information(this, tr("Erfolg"), tr("Daten werden in der Egg-Tabelle gespeichert"));
}

void EggDialog::updateHenAverageEggWeight()
{
    QSqlQuery query;
    query.prepare("UPDATE Hen SET Hen_AverageEggWeight = (SELECT AVG(Egg_Weight) FROM Egg WHERE Egg_HenID = Hen.Hen_ID AND Egg_Weight IS NOT NULL)");
    qDebug() << "AVG update";
    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", "Failed to update Hen_AverageEggWeight");
    }

}

void EggDialog::updateRoosterFertilizationRate()
{
    QSqlQuery updateQuery;
    updateQuery.prepare("UPDATE Rooster SET Rooster_FertilizationRate = "
                        "(SELECT CASE WHEN COUNT(*) > 0 THEN SUM(CAST(Egg_Fertilized AS int)) * 1.0 / COUNT(*) ELSE 0 END "
                        "FROM Egg WHERE Egg_RoosterID = Rooster.Rooster_ID)");

    qDebug() << "FertilizationRate update";
    if (!updateQuery.exec()) {
        QMessageBox::critical(this, "Database Error", "Failed to update Rooster_FertilizationRate");
    }
}

void EggDialog::updateHenLegeleistung()
{
    QSqlQuery query;
    query.prepare("UPDATE Hen SET Hen_Legeleistung = ("
                  "SELECT COUNT(*) * 1.0 / (DATEDIFF(DAY, MIN(Egg_DateLaid), MAX(Egg_DateLaid))+1) "
                  "FROM Egg "
                  "WHERE Egg_HenID = Hen.Hen_ID AND Egg_DateLaid IS NOT NULL "
                  "GROUP BY Egg_HenID"
                  ")");
    qDebug() << "Legeleistung update";
    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", "Failed to update Hen_Legeleistung");
    }
}

void EggDialog::on_btnSave_clicked()
{
    int ret = QMessageBox::question(this, tr("In Datenbank speichern"),
                                    tr("Möchten Sie die Änderungen in der Datenbank speichern?"),
                                    QMessageBox::Yes | QMessageBox::No);

       if (ret == QMessageBox::Yes) {
           saveToDatabase();
       }
       updateHenAverageEggWeight();
       updateRoosterFertilizationRate();
       updateHenLegeleistung();
}


void EggDialog::on_btnDelete_clicked()
{
    row = ui->tableView->currentIndex().row();
    model->removeRow(row);
}




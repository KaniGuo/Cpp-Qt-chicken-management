#ifndef EGGDIALOG_H
#define EGGDIALOG_H

#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QStandardItemModel>

namespace Ui {
class EggDialog;
}

class EggDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EggDialog(QWidget *parent = nullptr);
    ~EggDialog();

private slots:
    void on_btnAddNew_clicked();

    void on_btnInsert_clicked();

    void on_btnSave_clicked();

    void on_btnDelete_clicked();

private:
    Ui::EggDialog *ui;
    QSqlDatabase        dBase;
    QSqlQuery          *dbQuery;
    QStandardItemModel *model;
    QModelIndex         idx;

    void init();
    void dbOpen();
    void dbRead();
    void saveToDatabase();
    int  row{0};
    int  column{0};

    void updateHenAverageEggWeight();
    void updateRoosterFertilizationRate();
    void updateHenLegeleistung();
};

#endif // EGGDIALOG_H

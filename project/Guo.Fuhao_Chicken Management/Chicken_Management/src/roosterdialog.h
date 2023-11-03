#ifndef ROOSTERDIALOG_H
#define ROOSTERDIALOG_H

#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QStandardItemModel>

namespace Ui {
class RoosterDialog;
}

class RoosterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RoosterDialog(QWidget *parent = nullptr);
    ~RoosterDialog();

private slots:
    void on_btnInsert_clicked();

    void on_btnAddNew_clicked();

    void on_btnDelete_clicked();

    void on_btnSave_clicked();

private:
    Ui::RoosterDialog *ui;
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
};

#endif // ROOSTERDIALOG_H

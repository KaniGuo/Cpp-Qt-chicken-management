#ifndef HENDIALOG_H
#define HENDIALOG_H

#include <QDialog>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QStandardItemModel>

namespace Ui {
class HenDialog;
}

class HenDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HenDialog(QWidget *parent = nullptr);
    ~HenDialog();

private slots:
    void on_btnAddNew_clicked();

    void on_btnInsert_clicked();

    void on_btnSave_clicked();

    void on_btnDelete_clicked();

private:
    Ui::HenDialog       *ui;
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

#endif // HENDIALOG_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QStandardItemModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_btncfgRooster_clicked();

    void on_btncfgHen_clicked();

    void on_btncfgEgg_clicked();

    void on_rbRooster_clicked();

    void on_rbHen_clicked();

    void on_rbEgg_clicked();

    void on_btnSearch_clicked();

    void on_action_Sprache_triggered();

private:
    Ui::MainWindow *ui;
    QSqlDatabase        db;         //建立database
    QSqlQuery*          query;      //用于查询  select之类的  sql命令的使用
    QStandardItemModel *model;
    QModelIndex         idx;

    int  row{0};
    int  column{0};
};
#endif // MAINWINDOW_H

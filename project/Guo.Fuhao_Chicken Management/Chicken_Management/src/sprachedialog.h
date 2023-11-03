#ifndef SPRACHEDIALOG_H
#define SPRACHEDIALOG_H

#include <QDialog>
#include <QSettings>

namespace Ui {
class SpracheDialog;
}

class SpracheDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SpracheDialog(QWidget *parent = nullptr);
    ~SpracheDialog();

private slots:
    void on_rdGerman_clicked();

    void on_rdEnglish_clicked();

private:
    Ui::SpracheDialog *ui;
    void writeRegistry(QString lang);
};

#endif // SPRACHEDIALOG_H

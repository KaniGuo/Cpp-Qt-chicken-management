#include "sprachedialog.h"
#include "ui_sprachedialog.h"
#include <QMessageBox>

SpracheDialog::SpracheDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SpracheDialog)
{
    ui->setupUi(this);
}

SpracheDialog::~SpracheDialog()
{
    delete ui;
}

void SpracheDialog::on_rdGerman_clicked()
{
    writeRegistry("de");
}


void SpracheDialog::on_rdEnglish_clicked()
{
    writeRegistry("en");
}

void SpracheDialog::writeRegistry(QString lang)
{
    //Verbindung zur Registry herstellen
    QSettings registry("HKEY_CURRENT_USER\\Software", QSettings::IniFormat);

    //Eintrag in Registry vornehmen
    registry.setValue("chicken_management\\language", lang);

    QMessageBox::information(this, tr("Sprache geandert"),
                             tr("Sie haben eine andere Sprache gewahlt.\n, "
                             "Damit die Einstellung wirkt, starten Sie die Anwendung neu."));
}


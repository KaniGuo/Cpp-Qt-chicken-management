#include "mainwindow.h"

#include <QApplication>
#include <QSettings>        //Zum auslesen der Registry
#include <QTranslator>      //Fur Spracheinstellung


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSettings registry("HKEY_CURRENT_USER\\Software", QSettings::IniFormat);
    QString lang = registry.value("chicken_management\\language").toString();

    qDebug() << lang;

    QTranslator translator;
    QString languagefile = ":/language/translate_" + lang + ".qm";


    if(lang == "de")
        QVariant v = translator.load("");               // Für Deutsch
    else{
        qDebug() << languagefile;
        QVariant v = translator.load(languagefile);
    }

    a.installTranslator(&translator);



    MainWindow w;
    w.show();
    return a.exec();
}

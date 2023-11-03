QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    eggdialog.cpp \
    hendialog.cpp \
    main.cpp \
    mainwindow.cpp \
    roosterdialog.cpp \
    sprachedialog.cpp

HEADERS += \
    eggdialog.h \
    hendialog.h \
    mainwindow.h \
    roosterdialog.h \
    sprachedialog.h

FORMS += \
    eggdialog.ui \
    hendialog.ui \
    mainwindow.ui \
    roosterdialog.ui \
    sprachedialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

TRANSLATIONS += translate_en.ts \

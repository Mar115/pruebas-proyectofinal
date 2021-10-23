QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    enemigo1.cpp \
    inicio.cpp \
    jugador1.cpp \
    main.cpp \
    mainwindow.cpp \
    window2.cpp

HEADERS += \
    enemigo1.h \
    inicio.h \
    jugador1.h \
    mainwindow.h \
    window2.h

FORMS += \
    inicio.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagenes.qrc \
    images_game.qrc

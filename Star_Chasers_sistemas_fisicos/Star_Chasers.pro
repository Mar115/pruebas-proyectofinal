QT       += core gui\
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    asteroide.cpp \
    cuadros_de_dialogo.cpp \
    dialog.cpp \
    enemigo1.cpp \
    inicio.cpp \
    jugador1.cpp \
    main.cpp \
    mainwindow.cpp \
    proyectil.cpp \
    window2.cpp

HEADERS += \
    asteroide.h \
    cuadros_de_dialogo.h \
    dialog.h \
    enemigo1.h \
    inicio.h \
    jugador1.h \
    mainwindow.h \
    proyectil.h \
    variables_globales.h \
    window2.h

FORMS += \
    dialog.ui \
    inicio.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    audios.qrc \
    imagenes.qrc \
    images_game.qrc

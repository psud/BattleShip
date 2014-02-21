#-------------------------------------------------
#
# Project created by QtCreator 2014-02-19T09:01:45
#
#-------------------------------------------------

QT       += core gui
QT       += widgets

TARGET = BattleShip
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    values.cpp \
    controller.cpp \
    netinterface.cpp

HEADERS  += mainwindow.h \
    values.h \
    controller.h \
    netinterface.h

FORMS    += mainwindow.ui

RESOURCES += \
    ship.qrc






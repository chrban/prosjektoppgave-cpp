#-------------------------------------------------
#
# Project created by QtCreator 2015-04-14T11:25:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test4
TEMPLATE = app


SOURCES += main.cpp \
    myrect.cpp \
    bullet.cpp \
    enemy.cpp \
    rectfac.cpp \
    game.cpp \
    box.cpp \
    boxfactory.cpp

HEADERS  += \
    myrect.h \
    bullet.h \
    enemy.h \
    abstractfac.h \
    rectfac.h \
    game.h \
    box.h \
    object.h \
    boxfactory.h

RESOURCES += \
    res.qrc

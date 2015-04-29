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
    bullet.cpp \
    enemy.cpp \
    rectfac.cpp \
    game.cpp \
    box.cpp \
    boxfactory.cpp \
    figur.cpp \
    ground.cpp \
    groundfactory.cpp \
    linus.cpp \
    linusfactory.cpp \
    button.cpp \
    score.cpp \
    cloud.cpp \
    sun.cpp \
    cloudfactory.cpp \
    levelfactory.cpp \
    hp.cpp \
    superboss.cpp \
    globalvar.cpp \
    bossfactory.cpp \
    coursecreator.cpp

HEADERS  += \
    bullet.h \
    enemy.h \
    abstractfac.h \
    rectfac.h \
    game.h \
    box.h \
    object.h \
    boxfactory.h \
    figur.h \
    ground.h \
    groundfactory.h \
    linus.h \
    linusfactory.h \
    button.h \
    score.h \
    sun.h \
    cloud.h \
    cloudfactory.h \
    levelfactory.h \
    hp.h \
    superboss.h \
    globalvar.h \
    bossfactory.h \
    coursecreator.h

RESOURCES += \
    res.qrc

DISTFILES += \
    projectile.gif

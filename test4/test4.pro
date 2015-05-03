#-------------------------------------------------
#
# Project created by QtCreator 2015-04-14T11:25:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test4
TEMPLATE = app

CONFIG +=c++11


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
    coursecreator.cpp \
    enemyfactory.cpp

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
    coursecreator.h \
    enemyfactory.h

RESOURCES += \
    res.qrc

DISTFILES += \
    projectile.gif \
    img/projectile.gif \
    img/bossback.jpg \
    img/ground2.png \
    img/java1.png \
    img/java2.png \
    img/java3.png \
    img/large_cloud.png \
    img/linus-torvalds.png \
    img/mario1.png \
    img/mariohopp.png \
    img/mariohoppleft.png \
    img/marioleft.png \
    img/mariowalkleft.png \
    img/mariowalkleft2.png \
    img/mariowalkleft3.png \
    img/mariowalkleft4.png \
    img/mariowalkright.png \
    img/mariowalkright2.png \
    img/mariowalkright3.png \
    img/mariowalkright4.png \
    img/octocat1.png \
    img/octocat2.png \
    img/rorStdbackground.png \
    img/SKY.png \
    img/small_cloud.png \
    img/Stdbackground.png \
    img/sun1.png \
    img/sun2.png \
    img/wasted.png

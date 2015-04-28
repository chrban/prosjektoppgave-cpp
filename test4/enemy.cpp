#include "enemy.h"
#include <QPixmap>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <stdlib.h> //rand()

    enemy::enemy() : QObject() {
    //random position
    int random_number = rand() % 500;
    setPos(random_number,0);
    // set graphics
    setPixmap(QPixmap(":/new/img/boss.png"));

    //connect
    //QTimer * timer = new QTimer(this);
    //connect(timer,SIGNAL(timeout()).this,SLOT(move()));

    //timer->start(50);

}

void enemy::move() {
    setPos(x(),y()+5);

}

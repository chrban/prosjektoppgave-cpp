#include "enemy.h"
#include <QPixmap>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <stdlib.h> //rand()

    enemy::enemy(int x, int y) {
    // set graphics
    setPixmap(QPixmap(":/new/img/javaenemy.png"));

    //connect
    //QTimer * timer = new QTimer(this);
    //connect(timer,SIGNAL(timeout()).this,SLOT(move()));

    //timer->start(50);

}

void enemy::move() {
    setPos(x(),y()+5);

}

void enemy::animate()
{

}

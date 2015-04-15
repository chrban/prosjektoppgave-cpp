
#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

enemy::enemy()
{
    int random_number= rand()%700;
    setPos(random_number,0);
    setRect(0,0,100,100);

    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

void enemy::move()
{
    setPos(x(),y()+5);
    if(pos().y() + rect().height() < 0){
        scene()->removeItem(this);
        delete this;
    }

}

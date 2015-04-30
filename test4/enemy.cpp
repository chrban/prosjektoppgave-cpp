#include "enemy.h"
#include <QPixmap>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <stdlib.h> //rand()
#include <QObject>
#include <qmath.h>

    enemy::enemy(int x, int y) {
    // set graphics
    setPixmap(QPixmap(":/new/img/javaenemy.png"));
    setPos(x,y);
    m = new QTimer();
    s = new QTimer();
    connect(m,SIGNAL(timeout()),this,SLOT(move()));
    m->start(1000);
}
    void enemy::move() {
        count++;
        s->start(50);
        if(count == 1)
            connect(s,SIGNAL(timeout()),this,SLOT(left()));
        if(count == 2)
            connect(s,SIGNAL(timeout()),this,SLOT(right()));
        count = 0;
    }


void enemy::left(){
    setPos(x()-1,y()+1);
}

void enemy::right(){
    setPos(x()+1,y()+1);
}


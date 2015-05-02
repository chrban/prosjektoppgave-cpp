#include "superboss.h"
#include "bullet.h"
#include <QPixmap>
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QObject>
#include <qmath.h>
#include "game.h"

extern game * g;

superboss::superboss(int x, int y){
    // set graphics
    setPixmap(QPixmap(":/new/img/ironcat.png"));
    setPos(x,y);
    m = new QTimer();
    s = new QTimer();
    count = 0;
    health = 3;
    movements = true;
    connect(m,SIGNAL(timeout()),this,SLOT(move()));
    connect(s,SIGNAL(timeout()),this,SLOT(shoot()));
    m->start(3000);
    s->start(2000);
}

void superboss::move(){
    count++;
    if(count == 1){
        connect(m,SIGNAL(timeout()),this,SLOT(move()));
        movements=false;
        //for(int i=0;i<50;i++)
            setPos(x()-1,y()-1);
    }
    if(count == 2){
        connect(m,SIGNAL(timeout()),this,SLOT(move()));
        movements=true;
        //for(int i=0;i<50;i++)
            setPos(x(),y()+20);
    }
    if(count == 3){
        //for(int i=0;i<50;i++)
            setPos(x(),y()+30);
        count=0;
    }
}

void superboss::shoot(){
    bullet * b = new bullet();
    b->setPos(x()-50,y());
    scene()->addItem(b);
}

void superboss::setHealth(int h){
    health=h;
}

void superboss::decrease(){
    health--;
    if(health <= 0){
        g->showWinScreen();
        scene()->removeItem(this);
        delete this;
    }
}

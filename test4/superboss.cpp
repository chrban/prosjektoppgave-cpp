#include "superboss.h"
#include "bullet.h"
#include <QPixmap>
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QObject>
#include <qmath.h>

superboss::superboss(int x, int y){
    // set graphics
    setPixmap(QPixmap(":/new/img/ironcat.png"));
    setPos(x,y);
    m = new QTimer();
    s = new QTimer();
    count = 0;
    health = 3;
    connect(m,SIGNAL(timeout()),this,SLOT(move()));
    m->start(5000);
}

void superboss::move(){
    count++;
    s->start(50);
    if(count == 1)
        connect(s,SIGNAL(timeout()),this,SLOT(upLeft()));
    if(count == 2)
        connect(s,SIGNAL(timeout()),this,SLOT(upRight()));
    if(count == 3){
        connect(s,SIGNAL(timeout()),this,SLOT(down()));
        count=0;
    }
}

void superboss::upLeft(){
    setPos(x()-1,y()-1);
}

void superboss::upRight(){
    setPos(x()+1,y()-1);
}

void superboss::down(){
    setPos(x(),y()+2);
}

void superboss::shoot(){
    bullet * b = new bullet();
    b->setPos(x()-50,y());
    scene()->addItem(b);
}

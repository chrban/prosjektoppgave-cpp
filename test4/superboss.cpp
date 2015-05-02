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
    j = new QTimer();
    jmpr = new QTimer();
    count = 0;
    jump_count = 1;
    health = 3;
    direction = true;
    horizontal_direction = true;
    connect(m,SIGNAL(timeout()),this,SLOT(move()));
    connect(s,SIGNAL(timeout()),this,SLOT(shoot()));
    connect(j,SIGNAL(timeout()),this,SLOT(jump()));
    connect(jmpr,SIGNAL(timeout()),this,SLOT(jumper()));

    m->start(20);
    s->start(2000);
    j->start(2000);
}

void superboss::move(){

    if(count == 1){
        direction =true;
        //connect(m,SIGNAL(timeout()),this,SLOT(move()));
        //for(int i=0;i<50;i++)

    }
    else if(count == 2){
       // connect(m,SIGNAL(timeout()),this,SLOT(move()));

        //for(int i=0;i<50;i++)

    }
    else if(count == 30){
        //for(int i=0;i<50;i++)

       // count=0;
        direction =false;
    }

    if(direction){
        count++;
        setPos(x()-2,y());
    }
    else{
        count--;
        setPos(x()+2,y());
    }


}

void superboss::shoot(){
    bullet * b = new bullet();
    b->setPos(x()-50,y());
    scene()->addItem(b);
}
void superboss::jump(){
    jump_count = 1;
    jmpr->start(5);
}
void superboss::jumper(){

    if(jump_count==0){
        jmpr->stop();
        return;
    }

    if(jump_count ==30)
        horizontal_direction = false;

    if(horizontal_direction){
        jump_count++;
        setPos(x(),y()-2);
    }
    else{
        jump_count--;
        setPos(x(),y()+2);
    }
}


void superboss::setHealth(int h){
    health=h;
}

int superboss::getHealth()
{
    return health;
}

void superboss::decrease(){
    health--;
    g->bossHpCount=health;

}

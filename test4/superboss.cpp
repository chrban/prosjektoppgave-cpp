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
    setPixmap(QPixmap(":/images/octocat1.png"));
    setPos(x,y);
    m = new QTimer();
    s = new QTimer();
    j = new QTimer();
    jmpr = new QTimer();
    count = 0;
    jump_count = 0;
    health = 3;
    direction = true;
    horizontal_direction = true;
    connect(m,SIGNAL(timeout()),this,SLOT(move()));
    connect(s,SIGNAL(timeout()),this,SLOT(shoot()));
    connect(j,SIGNAL(timeout()),this,SLOT(jump()));
    connect(jmpr,SIGNAL(timeout()),this,SLOT(jumper()));

    m->start(90);
    s->start(700);
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

    if(count%2==0)
        setPixmap(QPixmap(":/images/octocat1.png"));
    else
        setPixmap(QPixmap(":/images/octocat2.png"));

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
    b->setPos(x()-10,y()+30);
    scene()->addItem(b);
}
void superboss::jump(){
    jump_count = 0;
    jmpr->start(5);
}
void superboss::jumper(){


    if(jump_count==0 && !horizontal_direction){
        jmpr->stop();
        horizontal_direction=true;
        return;
    }

    if(jump_count ==70)
        horizontal_direction = false;

    if(horizontal_direction){
        setPos(x(),y()-2);
        jump_count++;     
    }
    else{
        setPos(x(),y()+2);
        jump_count--;

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




#include "myrect.h"
#include "bullet.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include "enemy.h"
#include <QList>

myrect::myrect(){
    setPixmap(QPixmap(":/new/img/TUX3MINI.png"));
    falling = false;
    jumping = false;
    timer_up = new QTimer();
    velocity = 30;
    connect(timer_up,SIGNAL(timeout()),this,SLOT(jump()));

}


void myrect::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Left){
        if(x()>0)
            setPos(x()-10,y());

        QList<QGraphicsItem *> colliding_items = collidingItems();
        if(colliding_items.isEmpty() && !jumping){
            falling = true;
            timer_up->start();
        }
    }
    else if(event->key()==Qt::Key_Right){
        if(x()+100<800)
            setPos(x()+10,y());

        QList<QGraphicsItem *> colliding_items = collidingItems();
        if(colliding_items.isEmpty() && !jumping){
            falling = true;
            timer_up->start();
        }
    }
    else if(event->key()==Qt::Key_Up){
        jumping = true;
        timer_up->start(50);
    }

    else if(event->key()==Qt::Key_Space){
        bullet * bullet1 = new bullet();
        bullet1->setPos(x(),y());
        scene()->addItem(bullet1);
    }
}

void myrect::jump()
{
    if(falling){
        QList<QGraphicsItem *> colliding_items = collidingItems();
        if(!colliding_items.isEmpty()){
            //setPos(x(),colliding_items[0]->y());
            falling = false;
            timer_up->stop();
            velocity = 30;
            return;
        }
        else{
            setPos(x(),y()+velocity);
            velocity += 2;
        }
    }
    else if(velocity==0){
       jumping = false;
       falling = true;
    }
    else{
        setPos(x(),y()-velocity);
        velocity -=2;
    }
}



void myrect::spawn()
{
    enemy * enemyen = new enemy();
    scene()->addItem(enemyen);
}

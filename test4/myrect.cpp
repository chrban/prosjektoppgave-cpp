#include "myrect.h"
#include "bullet.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include "enemy.h"
#include <QList>

myrect::myrect(){
    setPixmap(QPixmap(":/new/img/mario1.png"));
    falling = false;
    jumping = false;
    walking = false;
    left= false;
    right = true;

    walk = 0;
    velocity = 30;

    timer_up = new QTimer();
    connect(timer_up,SIGNAL(timeout()),this,SLOT(jump()));

}


void myrect::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Left){
        left=true;
        right=false;
        walking = true;
        updateImg();

        if(x()>0)
            setPos(x()-10,y());

        QList<QGraphicsItem *> colliding_items = collidingItems();
        if(colliding_items.isEmpty() && !jumping){
            falling = true;
            velocity=15;
            timer_up->start();
        }
        walking =false;
        updateImg();
    }
    else if(event->key()==Qt::Key_Right){
        left=false;
        right=true;
        walking = true;
        updateImg();

        if(x()+50<800)
            setPos(x()+10,y());
        else{
            //scene()->clear();
            qDebug()<<"prenyttbrett";
            emit nyttBrett();

            return;
        }

        QList<QGraphicsItem *> colliding_items = collidingItems();
        if(colliding_items.isEmpty() && !jumping){
            falling = true;
            velocity=15;
            timer_up->start();
        }

        walking = false;
        updateImg();
    }
    else if(event->key()==Qt::Key_Up){
        jumping = true;
        walking = false;
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
    //if(jumping) setPixmap(QPixmap(":/new/img/mariohopp.png"));
    updateImg();

    if(falling){
         //setPixmap(QPixmap(":/new/img/mario1.png"));
        updateImg();
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
/*
void myrect::walk(){
    if(left){
        if(walk==3){
            timerWalk->stop();
            return;

        }

        if(x()>0)
            setPos(x()-10,y());

        QList<QGraphicsItem *> colliding_items = collidingItems();
        if(colliding_items.isEmpty() && !jumping){
            falling = true;
            velocity=15;
            timer_up->start();
        }

    }

}
*/
void myrect::updateImg(){
   /* if(jumping && right){
         setPixmap(QPixmap(":/new/img/mariohopp.png"));
    }
    else if(jumping && left)
         setPixmap(QPixmap(":/new/img/mariohoppleft.png"));
    else if(left && walking)
        setPixmap(QPixmap(":/new/img/marioleft.png"));
    else if(right && walking)
        setPixmap(QPixmap(":/new/img/mario1.png"));
        */
    if(jumping){
        if(right){
            setPixmap(QPixmap(":/new/img/mariohopp.png"));
        }
        else{
            setPixmap(QPixmap(":/new/img/mariohoppleft.png"));
            //setTransform(QTransform::fromScale(-1, 1));
        }
    }
    else if(walking){
        if(right){
            setPixmap(QPixmap(":/new/img/mariowalkright.png"));
        }
        else{
            setPixmap(QPixmap(":/new/img/mariowalkleft.png"));
        }
    }

    else if(left){
         setPixmap(QPixmap(":/new/img/marioleft.png"));
    }
    else if(right){
         setPixmap(QPixmap(":/new/img/mario1.png"));
    }
}




void myrect::spawn()
{
    enemy * enemyen = new enemy();
    scene()->addItem(enemyen);
}

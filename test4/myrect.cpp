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
    timer = 5;

    walked = 0;
    velocity = 50;

    timer_up = new QTimer();
    timerWalk = new QTimer();
    connect(timer_up,SIGNAL(timeout()),this,SLOT(jump()));
    connect(timerWalk,SIGNAL(timeout()),this,SLOT(walk()));

}


void myrect::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Left){
        left=true;
        right=false;
        walking = true;


        if(x()>0){
            if(falling){
                updateImg();
                 timerWalk->start();
                //setPos(x()-3,y());
                return;
            }
           // if(!jumping){
                if(timerWalk->isActive())
                    return;

                timerWalk->start(20);
                //setPos(x()-10,y());
           // }
        }

        updateImg();
        QList<QGraphicsItem *> colliding_items = collidingItems();
        if(colliding_items.isEmpty() && !jumping){
            falling = true;
            updateImg();
            velocity=0;
            timer_up->start(9);
        }
        walking =false;
        updateImg();
    }
    else if(event->key()==Qt::Key_Right){
        left=false;
        right=true;
        walking = true;

        if(x()>800){
            //scene()->clear();
            qDebug()<<"prenyttbrett";
            emit nyttBrett();

            return;

        }
        else{
            if(falling){
                updateImg();
                timerWalk->start();
               // setPos(x()+3,y());

                //return;
            }
            //if(!jumping){
                if(timerWalk->isActive())
                    return;
                timerWalk->start(20);
                //setPos(x()+10,y());
                //return;
            //}

        }


        updateImg();
        QList<QGraphicsItem *> colliding_items = collidingItems();
        if(colliding_items.isEmpty() && !jumping){
            falling = true;
            updateImg();
            velocity=0;
            timer_up->start(9);
        }

        walking = false;
        updateImg();
    }
    else if(event->key()==Qt::Key_Up){
        if(!falling)
            jumping = true;
        walking = false;
        timer_up->start(3);
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
            setPos(x(),y());
            falling = false;
            jumping = false;
            timer_up->stop();
            walked=0;
            velocity = 30;
            return;
        }
        else{
            //setPos(x(),y()+velocity);
            if(velocity <15 && timer>3){
                timer -= 1;

                timer_up->setInterval(timer);
            }
            else
                timer =0;
            setPos(x(),y()+3);
            //if(velocity<15)
                velocity += 1;
        }
    }
    else if(velocity==0){
       jumping = false;
       falling = true;
    }
    else{
        QList<QGraphicsItem *> colliding_items = collidingItems();
        if(!colliding_items.isEmpty() && velocity<28){
            if(y()+30>colliding_items[0]->y()){
                setPos(x(),y()+10);
                if(x() < colliding_items[0]->x()){
                    setPos(x()-5,y());
                }
                else
                    setPos(x()+5,y());
            }

            //setPos(x(),y()+5);
            falling = true;
            jumping =false;
            updateImg();
            velocity = 15;
            timer =11;
            return;
        }

        if(velocity < 16 && timer<12){
            timer += 1;
            timer_up->setInterval(timer);
        }
      //  setPos(x(),y()-velocity);
        setPos(x(),y()-3);
        velocity -=1;
    }
}

void myrect::walk()
{
   if(falling || jumping){
       walked++;

       if(walked>20){
           walked = 0;
           timerWalk->stop();
           return;
       }

       if(left){
           setPos(x()-2,y());

           QList<QGraphicsItem *> colliding_items = collidingItems();
           if(!colliding_items.isEmpty() && colliding_items.back()->y() > y()-30){
                   setPos(x()+2,y());
                   qDebug()<<"prømpleft";
                   timerWalk->stop();
           }


           return;
       }
       setPos(x()+2,y());
       QList<QGraphicsItem *> colliding_items = collidingItems();
       if(!colliding_items.isEmpty() && colliding_items.back()->y() > y()-30){
               setPos(x()-2,y());
               qDebug()<<"prømpright";
               timerWalk->stop();
       }
       return;
   }

   if(left){

       if(walked>7){
         setPixmap(QPixmap(":/new/img/mariowalkleft4.png"));

       }
       else if(walked>5){
        setPixmap(QPixmap(":/new/img/mariowalkleft3.png"));

       }
       else if(walked>3){
        setPixmap(QPixmap(":/new/img/mariowalkleft2.png"));

       }
       else{
        setPixmap(QPixmap(":/new/img/mariowalkleft.png"));

       }
       setPos(x()-2,y());

       QList<QGraphicsItem *> colliding_items = collidingItems();
       if(!colliding_items.isEmpty() && colliding_items.back()->y() < y()+26 && colliding_items.back()->y()!=0){
               setPos(x()+2,y());
               qDebug()<<"kollisjon på venstre side: vår y: "<<y()<<"  boksen sin y: "<<colliding_items.back()->y();

               timerWalk->stop();
       }

       walked++;
       if(walked == 10){
           setPixmap(QPixmap(":/new/img/marioleft.png"));
           walked =0;
           timerWalk->stop();
           return;
       }
       return;
   }

   if(walked>7){
     setPixmap(QPixmap(":/new/img/mariowalkright4.png"));

   }
   else if(walked>5){
    setPixmap(QPixmap(":/new/img/mariowalkright3.png"));

   }
   else if(walked>3){
    setPixmap(QPixmap(":/new/img/mariowalkright2.png"));

   }
   else{
    setPixmap(QPixmap(":/new/img/mariowalkright.png"));

   }

   setPos(x()+2,y());

   QList<QGraphicsItem *> colliding_items = collidingItems();
   if(!colliding_items.isEmpty() && colliding_items.back()->y() < y()+26 && colliding_items.back()->y() !=0){
           setPos(x()-2,y());
           qDebug()<<"kollisjon på høyre side";
           timerWalk->stop();
   }

   walked++;
   if(walked == 10){
       setPixmap(QPixmap(":/new/img/mario1.png"));
       walked=0;
       timerWalk->stop();
       return;
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
        if(!jumping && !falling){

            if(right){
                setPixmap(QPixmap(":/new/img/mariowalkright.png"));
            }
            else{
                setPixmap(QPixmap(":/new/img/mariowalkleft.png"));
            }
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

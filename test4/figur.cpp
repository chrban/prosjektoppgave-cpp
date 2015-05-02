#include "figur.h"
#include "bullet.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include <typeinfo>
#include "enemy.h"
#include "cloud.h"
#include <QList>
#include "linus.h"
#include "score.h"
#include "game.h"
#include "hp.h"
#include "superboss.h"
//#include "levelfactory.h"

extern game * g; //global variable
//extern LevelFactory * lf;

Figur::Figur(){
    setPixmap(QPixmap(":/new/img/mario1.png"));


    //states
    falling = false;
    jumping = false;
    walking = false;
    left= false;
    right = true;
    superspeed=0;


    //tellere
    timer = 5;
    walked = 0;
    velocity = 30;

    //timers
    timer_for_jump = new QTimer();
    timer_for_walk = new QTimer();
    timer_scanner = new QTimer();
    connect(timer_for_jump,SIGNAL(timeout()),this,SLOT(jump()));
    connect(timer_for_walk,SIGNAL(timeout()),this,SLOT(walk()));
    connect(timer_scanner,SIGNAL(timeout()),this,SLOT(scanner()));

}


void Figur::keyReleaseEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Left){
        //left=false;
        walking = false;
        timer_for_walk->stop();
        setPixmap(QPixmap(":/new/img/marioleft.png"));
        timer_scanner->stop();
    }

    if(event->key()==Qt::Key_Right){
        setPixmap(QPixmap(":/new/img/mario1.png"));
        walking = false;
        timer_for_walk->stop();
        timer_scanner->stop();
    }

    if(event->key()==Qt::Key_Up){//slipper hoppknappen
        jumping=false;
    }

    if(event->key()==Qt::Key_Space){
        superspeed=0;
    }
}


void Figur::keyPressEvent(QKeyEvent *event)
{
    // VENSTRE
    if(event->key()==Qt::Key_Left){
        //setter states
        left=true;
        right=false;
        walking = true;
        timer_scanner->start();

             QList<QGraphicsItem *> colliding_items2 = collidingItems(Qt::IntersectsItemShape);
             QList<QGraphicsItem *> colliding_items = collidingItems();
             for(int i = 0, n= colliding_items.size();i<n;i++){
                  if(typeid(*(colliding_items[i]))==typeid(enemy)){
                             scene()->removeItem(colliding_items[i]);
                             delete colliding_items[i];
                             g->hp->decrease();
                             return;
                }
             }
             if(falling && colliding_items2.isEmpty() /*&& !timer_for_walk->isActive()*/){
                updateImg();
                //starter timer som beveger figur horisontalt mens den er i luften
                timer_for_walk->start();
                return;
            }

            if(timer_for_walk->isActive())// ikke start timer på nytt hvis den allerede kjører
                return;

            // starter timer som får figuren til å gå bortove, med mindre den støter på noe.
            timer_for_walk->start(20);


        //trengs denne?
        updateImg();


        // dette er kode som sjekker om figuren går utenfor noe og skal falle ned
        // vil egentlig sjekke for dette i walk-slotten, som er
        // bedre, for der kan man sjekke oftere.

        walking =false;
        updateImg();

    } // HØYRE
    else if(event->key()==Qt::Key_Right){
        //setter states
        left=false;
        right=true;
        walking = true;
        timer_scanner->start();

            QList<QGraphicsItem *> colliding_items2 = collidingItems(Qt::IntersectsItemShape);
            QList<QGraphicsItem *> colliding_items = collidingItems();
            for(int i = 0, n= colliding_items.size();i<n;i++){
                 if(typeid(*(colliding_items[i]))==typeid(enemy)){
                            scene()->removeItem(colliding_items[i]);
                            delete colliding_items[i];
                            g->hp->decrease();
                            return;
                }
            }
            if(colliding_items2.isEmpty())qDebug()<<"kolliderer ikke med noe!";


            // ikke start timer på nytt hvis den allerede kjører
            if(timer_for_walk->isActive())
                return;

             // starter timer som får figuren til å gå bortove, med mindre den støter på noe.
            timer_for_walk->start(20);


        updateImg();


        // dette er kode som sjekker om figuren går utenfor noe og skal falle ned
        // vil egentlig sjekke for dette i walk-slotten, som er
        // bedre, for der kan man sjekke oftere.

        walking = false;
        updateImg();

     // HOPPER
    }
    else if(event->key()==Qt::Key_Up){
        //ikke hopp hvis du faller!
        if(!falling)
        {
            jumping = true;
            walking = false;

        //start hoppetimeren
        timer_for_jump->start(0);
        }
    } 
        else if(event->key()==Qt::Key_Space){
        superspeed=10;
    }
}


void Figur::jump()
{
    updateImg();//trengs denne?

    //Figur faller
    if(falling){

        // Figur har falt gjennom gulvet, resettes, og mister HP
        if(y()>700){
            setPos(10,520);
            falling=false;
            jumping=false;
            timer_for_jump->stop();
            walked=0;
            velocity=30;
            g->hp->decrease();
            return;
        }

        QList<QGraphicsItem *> colliding_items = collidingItems();
        // Tux har truffet noe på vei ned.
        if(!colliding_items.isEmpty()){

            // krasjer han i siden på noe på vei ned?
            if(colliding_items.back()->y() < y()+20){
               //på høyresiden av tingen

               if(colliding_items.back()->x()>x()){
                    setPos(x()-2,y());

               }
               //på venstresiden
               else{

                   setPos(x()+2,y());
                }


               //uansett side, flyttes figuren litt vekk fra den. Da fjernes det den
               //krasjet i fra collidingitems og figuren fortsetter å falle
            }

            //Figuren har landet på toppen av noe
            else{
                //figuren stopper opp der den lander, stopper timer, resetter tellere.


                for(int i = 0, n= colliding_items.size();i<n;i++){
                     if(typeid(*(colliding_items[i]))==typeid(Linus)){
                                scene()->removeItem(colliding_items[i]);
                                delete colliding_items[i];
                                g->score->increase();
                                return;
                            }
                     if(typeid(*(colliding_items[i]))==typeid(superboss)){
                                g->sb->decrease();
                                return;
                            }
                }

                for(int i = 0, n= colliding_items.size();i<n;i++){
                                     if(typeid(*(colliding_items[i]))==typeid(enemy)){
                                                scene()->removeItem(colliding_items[i]);
                                                delete colliding_items[i];
                                                g->score->increase();
                                                return;
                                            }

                                }

                setPos(x(),y());
                falling = false;
                jumping = false;
                walked=0;
                updateImg();
                timer_for_jump->stop();
                velocity = 30;
                return;
            }
        }
        //Figuren krasjer ikke med noe og faller videre nedover.
        else{
            // øker farten i begynnelsen av fallet, helt til figuren når treminal velocity
            if(velocity <15 && timer>0){
                timer -= 1;

                timer_for_jump->setInterval(timer);
            }
            else
                timer =0;

            //flytter nedover
            setPos(x(),y()+3);
            velocity += 1;
        }
    }
    // Nådd toppen! snur og begynner og falle
    else if(velocity==0){
       jumping = false;
       falling = true;
    }
    // Hopper oppover
    else{ // (!falling)
        // Krasjer figuren i noe på vei opp?
        QList<QGraphicsItem *> colliding_items = collidingItems();
        //krasjer i noe
        if(!colliding_items.isEmpty() && velocity<28){
//            qDebug()<<"krasjer på vei opp";
            // Treffer noe på siden
            for(int i = 0, n= colliding_items.size();i<n;i++){
                 if(typeid(*(colliding_items[i]))==typeid(Linus)){
                            scene()->removeItem(colliding_items[i]);
                            delete colliding_items[i];
                            g->score->increase();
                            return;
                 }

            }

            if(y()>colliding_items[0]->y()+14){
//                qDebug()<< "strengt under";
                setPos(x(),y()+3);

            }
            else if(y()+27>colliding_items[0]->y()){
                setPos(x(),y()-5);
//                qDebug()<< "strengt over";

                //treffer noe på høyresiden
                if(x() < colliding_items[0]->x()){
                    //setPos(x(),y());
                    setPos(x()-5,y());

                }
                // treffer noe på venstresiden
                else
                    setPos(x()+5,y());

                return;
            }

            // Slutter å hoppe og begynner å falle
            falling = true;
            jumping =false;
            updateImg();
            velocity = 0;
            timer = 11;// burde denne være noe annet?
            return;
        }

        // Senker hastigheten på toppen av hoppet
        if(velocity < 15 && timer<12){
            timer += 1;
            timer_for_jump->setInterval(timer);
        }
        // flytter oppover
        setPos(x(),y()-3);
        velocity -=1;
    }
}

void Figur::walk()
{
   // horisontal bevegelse i luften
   if(falling || jumping){
       walked++;
       updateImg();// trengs denne?

       // Flytter seg til venstre
       if(left){
           setPos(x()-4-superspeed,y());

           //Treffer noe på siden
           QList<QGraphicsItem *> colliding_items = collidingItems();
           if(!colliding_items.isEmpty() && colliding_items.back()->y() > y()-28){
                   setPos(x()+2,y());
           }
           updateImg();

           return;
       }

       //Flytter seg til høyre
       setPos(x()+4+superspeed,y());

       // Treffer noe på siden
       QList<QGraphicsItem *> colliding_items = collidingItems();
       if(!colliding_items.isEmpty() && colliding_items.back()->y() > y()-28){
               setPos(x()-2,y());
       }
       return;
   }


   // Står på bakken og vil flytte seg til venstre
   if(left){


       // velger bilder for animasjonen. Må flytte dette til updateImg
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



       //flytter venstre


       // Faller utenfor et stup!
       QList<QGraphicsItem *> colliding_items1 = collidingItems();
       if(colliding_items1.isEmpty() && !jumping){
           falling = true;
           walked =0;
           velocity=0;
           timer_for_jump->start(11);
           return;
       }

       setPos(x()-4-superspeed,y());

       for(int i = 0, n= colliding_items1.size();i<n;i++){
           if(typeid(*(colliding_items1[i]))==typeid(Linus)){
               scene()->removeItem(colliding_items1[i]);
               //increase score
               delete colliding_items1[i];
               g->score->increase();
               return;
           }
       }

       // Treffer en dings
       QList<QGraphicsItem *> colliding_items = collidingItems();
       if(!colliding_items.isEmpty() && colliding_items.back()->y() < y()+23 && colliding_items.back()->y()!=0){
               setPos(x()+4,y());
               setPixmap(QPixmap(":/new/img/marioleft.png"));// gjør det i updateImg
               walked=0;
               walking = false;
               return;
       }

       walked++;

       // ferdig å gå
       if(walked == 10){
           setPixmap(QPixmap(":/new/img/marioleft.png"));
           walked =0;
           return;
       }
       return;
   }


   // GÅR TIL HØYRE

   // switchcase? prøvde, fikk det ikke helt til
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

   //flytter høyre
   setPos(x()+4+superspeed,y());




   // FAller utfor et stup!
   QList<QGraphicsItem *> colliding_items = collidingItems();
   if(colliding_items.isEmpty() && !jumping){
       falling = true;
       walked=0;
       velocity=0;
       timer_for_jump->start(11);
       return;
   }

   for(int i = 0, n= colliding_items.size();i<n;i++){
      if(typeid(*(colliding_items[i]))==typeid(Linus)){
           scene()->removeItem(colliding_items[i]);
           delete colliding_items[i];
           g->score->increase();
           return;
       }
   }

   // treffer en dings
   if(!colliding_items.isEmpty() && colliding_items.back()->y() < y()+23 && colliding_items.back()->y() !=0){
           setPos(x()-4,y());
           setPixmap(QPixmap(":/new/img/mario1.png"));
           walked=0;
           walking=false;
           return;
   }

   walked++;

   //ferdig å gå
   if(walked == 10){
       setPixmap(QPixmap(":/new/img/mario1.png"));
       walked=0;
       return;
   }
}

void Figur::scanner()
{
    // Hvis man går ut av brettet på høyre side, skal et nytt brett lages.
    if(x()>770){
        g->GV->increaseFrame();
        emit gott_av_banen();// sender signal til slot i game som lager nytt brett
        return;
    }else if(x()<5)//gått til venster
    {

        //kommenter inn hvis man skal kunne gå til venstre.
//       if(g->GV->getFrame() > 0 )
//            {
//                g->GV->decreaseFrame();
//                emit gott_av_banen();// sender signal til slot i game som lager nytt brett
//            }


        //kan ikke gå utenfor banen.
        setPos(x()+1,y()); //kan ikke gå hvis ikke noe der

    }


}

// Må bruke denne mer? God ide å basere alt på states og tellere?
void Figur::updateImg(){
    if(jumping){
        if(right){
            setPixmap(QPixmap(":/new/img/mariohopp.png"));
        }
        else{
            setPixmap(QPixmap(":/new/img/mariohoppleft.png"));
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



// fra youtube
//void Figur::spawn()
//{
//    enemy * fiende = new enemy();
//    scene()->addItem(fiende);
//}

#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include <QFont>
#include <QDebug>
#include "Enemy.h"
#include "rectfac.h"
#include "boxfactory.h"
#include "groundfactory.h"
#include "linusfactory.h"
#include <QBrush>
#include <QImage>
#include <QMediaPlayer>

game::game(QWidget *parent) : linusCount(0){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage("://new/img/Stdbackground.png")));




    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    //tux = new myrect();

   // connect(tux,SIGNAL(nyttBrett()),this,SLOT(setUp()));

    setUp();

    show();
}

void game::setUp(){

    scene->clear();
    qDebug()<<"post";


    // setter opp bokser og bakke
    boxFactory * hinderFabrikk2 = new boxFactory();
    GroundFactory * bakkeFabrikk = new GroundFactory();
    LinusFactory * linusFabrikk = new LinusFactory();

    for(int i = 0; i<10;i++){
        scene->addItem(hinderFabrikk2->mekk());

    }
    for(int i = 0; i < 29;i++)
       scene->addItem(bakkeFabrikk->mekk());

    for(int i = 0;i < 3;i++){
        scene->addItem(linusFabrikk->mekk());
    }



   // QGraphicsRectItem* bakke = new QGraphicsRectItem();
    tux = new Figur();
    connect(tux,SIGNAL(nyttBrett()),this,SLOT(setUp()));
    connect(tux,SIGNAL(pickedUpALinus()),this,SLOT(pickedUpLinus()));
    tux->setPos(10,520);
    tux->setFlag(QGraphicsItem::ItemIsFocusable);
    tux->setFocus();
   // bakke->setRect(-1,height()-50,800,31);

   // scene->addItem(bakke);
    scene->addItem(tux);

    qDebug()<<"prefac";
    /*rectFac * hinderFabrikk = new rectFac();

    for(int i = 0; i<5;i++){
        scene->addItem(hinderFabrikk->mekk());
    }
*/

    //delete hinderFabrikk;
    //delete hinderFabrikk2;
}

void game::pickedUpLinus()
{
    linusCount++;
    if(linusCount%3==0)
        qDebug()<<"Plukket opp alle linuser";
}

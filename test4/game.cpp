#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include <QFont>
#include <QDebug>
#include "Enemy.h"
#include "rectfac.h"
#include "boxfactory.h"
#include <QBrush>
#include <QImage>

game::game(QWidget *parent){
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

    boxFactory * hinderFabrikk2 = new boxFactory();

    for(int i = 0; i<20;i++){
        scene->addItem(hinderFabrikk2->mekk());
    }

   // hinderFabrikk2->mekk


    QGraphicsRectItem* bakke = new QGraphicsRectItem();
    tux = new myrect();
    connect(tux,SIGNAL(nyttBrett()),this,SLOT(setUp()));
    tux->setPos(10,520);
    tux->setFlag(QGraphicsItem::ItemIsFocusable);
    tux->setFocus();
    bakke->setRect(-1,height()-50,800,31);

    scene->addItem(bakke);
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

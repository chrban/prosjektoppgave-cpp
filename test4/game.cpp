#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include <QFont>
#include <QDebug>
#include "Enemy.h"
#include "rectfac.h"

game::game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)

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


    QGraphicsRectItem* bakke = new QGraphicsRectItem();
    tux = new myrect();
    connect(tux,SIGNAL(nyttBrett()),this,SLOT(setUp()));
    tux->setPos(10,520);
    tux->setFlag(QGraphicsItem::ItemIsFocusable);
    tux->setFocus();
    bakke->setRect(-1,height()-30,800,31);

    scene->addItem(bakke);
    scene->addItem(tux);

    qDebug()<<"prefac";
    rectFac * hinderFabrikk = new rectFac();

    for(int i = 0; i<5;i++){
        scene->addItem(hinderFabrikk->mekk());
    }
    delete hinderFabrikk;
}

#include "Game.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include <QFont>
#include <QDebug>
#include "rectfac.h"
#include "boxfactory.h"
#include "groundfactory.h"
#include "linusfactory.h"
#include <QBrush>
#include <QImage>
#include <QMediaPlayer>
#include "button.h"




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
}

void game::showMainMenu(){
    QGraphicsTextItem* title = new QGraphicsTextItem(QString("C++"));
    QFont titleFont("Helvetica",40);
    title->setFont(titleFont);
    int txPos = this->width()/2-title->boundingRect().width()/2;
    int tyPos = 150;
    title->setPos(txPos,tyPos);
    scene->addItem(title);

    Button* play = new Button(QString("Play game"));
    int bxPos = this->width()/2-play->boundingRect().width()/2;
    int byPos = 275;
    play->setPos(bxPos, byPos);
    connect(play, SIGNAL(clicked()), this, SLOT(setUp()));
    scene->addItem(play);

    Button* quit = new Button(QString("Quit game"));
    int qxPos = this->width()/2 - play->boundingRect().width()/2;
    int qyPos = 350;
    quit->setPos(qxPos, qyPos);
    connect(quit, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quit);
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
    tux->setPos(10,520);
    tux->setFlag(QGraphicsItem::ItemIsFocusable);
    tux->setFocus();
   // bakke->setRect(-1,height()-50,800,31);

   // scene->addItem(bakke);
    scene->addItem(tux);

    //lager enemy
     enemy * fiende = new enemy();
     scene->addItem(fiende);
     fiende->setPos(10,520);


    qDebug()<<"prefac";
    /*rectFac * hinderFabrikk = new rectFac();

    for(int i = 0; i<5;i++){
        scene->addItem(hinderFabrikk->mekk());
    }
*/

    //delete hinderFabrikk;
    //delete hinderFabrikk2;

    show();
}

void game::pickedUpLinus()
{

}

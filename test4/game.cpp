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
#include "cloudfactory.h"
#include "levelfactory.h"
#include <QBrush>
#include <QImage>
#include <QMediaPlayer>
#include "button.h"
#include "sun.h"

game::game(QWidget * parent){
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

//    setUp();
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
    int qyPos = 400;
    quit->setPos(qxPos, qyPos);
    connect(quit, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quit);

    show();
}

void game::setUp(){


    scene->clear();
    qDebug()<<"post";

    Sun * sun = new Sun(680,30);
    scene->addItem(sun);
    // setter opp bokser og bakke
    boxFactory * hinderFabrikk2 = new boxFactory();
    GroundFactory * bakkeFabrikk = new GroundFactory();
    CloudFactory * cloudFabrikk = new CloudFactory();
    LinusFactory * linusFabrikk = new LinusFactory();
    LevelFactory * levelFabrikk = new LevelFactory();


    for(int i = 0; i<10;i++){
        scene->addItem(cloudFabrikk->mekk());
    }

    for(int i = 0; i<4;i++){
        scene->addItem(hinderFabrikk2->mekk(levelFabrikk->getNextX(),levelFabrikk->getNextY()));

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

    //lager score
    score = new Score();
    scene->addItem(score);

    //lager HP
    hp = new Hp();
    hp->setPos(0,20);
    scene->addItem(hp);

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

    //background music
    //FUNKERRRRRRRRRRR HURRA
    //QMediaPlayer * music = new QMediaPlayer();
    //music->setMedia(QUrl("qrc:/new/sounds/Super Mario Bros Official Theme Song.mp3"));
    //music->play();


    show();
}

void game::pickedUpLinus()
{



}

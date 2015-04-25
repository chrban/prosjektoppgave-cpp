#include "Game.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
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
#include "button.h"
#include "sun.h"
#include <QPixmap>

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

    hpCount=3;
    scoreCount=0;

}

void game::showMainMenu(){
    scene->clear();

    QGraphicsTextItem* title = new QGraphicsTextItem(QString("C++"));
    QFont titleFont("Helvetica",40);
    title->setFont(titleFont);
    int txPos = this->width()/2-title->boundingRect().width()/2;
    int tyPos = 150;
    title->setPos(txPos,tyPos);
    scene->addItem(title);

    setBackgroundBrush(QBrush(QImage("://new/img/tuxvsgit.png")));

    Button* play = new Button(QString("PLAY GAME"));
    int bxPos = this->width()/2-play->boundingRect().width()/2;
    int byPos = 425;
    play->setPos(bxPos, byPos);
    connect(play, SIGNAL(clicked()), this, SLOT(setUp()));
    scene->addItem(play);

    Button* quit = new Button(QString("QUIT GAME"));
    int qxPos = this->width()/2 - play->boundingRect().width()/2;
    int qyPos = 460;
    quit->setPos(qxPos, qyPos);
    connect(quit, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quit);

    show();
}

void game::setUp(){

    scene->clear();
    setBackgroundBrush(QBrush(QImage("://new/img/Stdbackground.png")));
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





    levelFabrikk->readMap();
    for(int i = 0; i<13;i++)
    scene->addItem( hinderFabrikk2->mekkFromPair( ( levelFabrikk->getCoordinates() )) );


    for(int i = 0; i < 29;i++)
       scene->addItem(bakkeFabrikk->mekk());

    for(int i = 0;i < 3;i++){
        scene->addItem(linusFabrikk->mekk(levelFabrikk->getNextX(),levelFabrikk->getNextY()));
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
    score->increase(scoreCount);
    scene->addItem(score);

    //lager HP
    hp = new Hp();
    hp->setPos(0,20);
    hp->setHp(hpCount);
    scene->addItem(hp);

    //lager enemy
     enemy * fiende = new enemy();
     scene->addItem(fiende);
     fiende->setPos(10,520);



    /*rectFac * hinderFabrikk = new rectFac();

    for(int i = 0; i<5;i++){
        scene->addItem(hinderFabrikk->mekk());
    }
*/

    //delete hinderFabrikk;
    //delete hinderFabrikk2;

    //background music
    //FUNKERRRRRRRRRRR HURRA

    /*
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/new/sounds/Super Mario Bros Official Theme Song.mp3"));
    music->play();
*/
    show();
}

void game::showKillScreen(){
    // Disable GraphicItems
    foreach(QGraphicsItem* item, scene->items())
        item->setEnabled(false);

    // Legg til transparent-panel
    QGraphicsRectItem* panel = new QGraphicsRectItem(0,0,800,600);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    panel->setBrush(brush);
    panel->setOpacity(0.65);
    scene->addItem(panel);

    // Wasted :):):)
    QGraphicsPixmapItem* wasted = scene->addPixmap(QPixmap(":/new/img/wasted.png"));
    wasted->setPos(250,100);

    // Vis endelig score
    QGraphicsTextItem* finalScore = new QGraphicsTextItem();
    finalScore->setPlainText("Final Score: "+QString::number(scoreCount));
    finalScore->setDefaultTextColor(Qt::yellow);
    finalScore->setFont(QFont("tahoma",20));
    finalScore->setPos(330,325);
    scene->addItem(finalScore);

    // Legg til Main Menu-knapp
    Button* menu = new Button(QString("Main Menu"));
    menu->setPos(300,400);
    connect(menu, SIGNAL(clicked()), this, SLOT(showMainMenu()));
    scene->addItem(menu);

    show();

    hpCount=3;
    scoreCount=0;
}

void game::pickedUpLinus(){

}

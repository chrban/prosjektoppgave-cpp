#include "enemy.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QFont>
#include <QDebug>
#include "rectfac.h"
//#include "boxfactory.h"
#include "groundfactory.h"
#include "linusfactory.h"
#include "cloudfactory.h"
#include "levelfactory.h"
#include <QBrush>
#include <QImage>
#include "button.h"
#include "sun.h"
#include <QPixmap>
#include "superboss.h"
#include "globalvar.h"
#include "coursecreator.h"
#include "game.h"


game::game(QWidget * parent){
    // create the scene
    Q_UNUSED(parent); //debugger?
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
    frameCount = 0;
    requiredScoreCount=40;
    bossHpCount=3;


}

void game::showMainMenu(){

    scene->clear();

    QGraphicsTextItem* title = new QGraphicsTextItem(QString("Tux goes postal!")); // for teh lulz
    QFont titleFont("Comic Sans MS",40);
    title->setFont(titleFont);
    title->setDefaultTextColor(Qt::red);
    int txPos = this->width()/2-title->boundingRect().width()/2;
    int tyPos = 180;
    title->setPos(txPos,tyPos);
    scene->addItem(title);

    setBackgroundBrush(QBrush(QImage("://new/img/tuxvsgit.png")));

    Button* play = new Button(QString("PLAY GAME"));
    int bxPos = this->width()/2-play->boundingRect().width()/2;
    int byPos = 425;
    play->setPos(bxPos, byPos);
    connect(play, SIGNAL(clicked()), this, SLOT(setUp()));
    scene->addItem(play);

    Button* create = new Button(QString("CREATE MAP"));
    int cxPos = this->width()/2 - play->boundingRect().width()/2;
    int cyPos = 460;
    create->setPos(cxPos, cyPos);
    connect(create, SIGNAL(clicked()),this,SLOT( showEditorScreen() ));
//    connect(quit, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(create);

    Button* quit = new Button(QString("QUIT GAME"));
    int qxPos = this->width()/2 - play->boundingRect().width()/2;
    int qyPos = 495;
    quit->setPos(qxPos, qyPos);
    connect(quit, SIGNAL(clicked()), this, SLOT(close()));
    scene->addItem(quit);


    show();
}

void game::setUp(){

    scene->clear();



    setBackgroundBrush(QBrush(QImage("://new/img/Stdbackground.png")));

    Sun * sun = new Sun(680,30);//flyttes - chrban
    scene->addItem(sun);

    //lager score
    score = new Score();
    score->increase(scoreCount);
    scene->addItem(score);

    //frameNr
    GV = new GlobalVar();
    GV-> setFrame(frameCount);
    GV->setRequiredScore(requiredScoreCount);


    if(scoreCount >= GV->getRequiredScore() ){ //aktiverer bossbattle som neste frame
        setBackgroundBrush(QBrush(Qt::red));
        SB = new superboss(700,450);
        scene->addItem( SB );
        SB->setHealth(  bossHpCount );
        frameCount = 1337;
        //BOSSBATTLE!
        QGraphicsTextItem* bossText = new QGraphicsTextItem();
        bossText->setPlainText("Boss Battle!");
        bossText->setDefaultTextColor(Qt::yellow);
        bossText->setFont(QFont("tahoma",20));
        bossText->setPos(350,10);
        scene->addItem(bossText);
    }

    LevelFactory * LF = new LevelFactory;
    LF->loadMap( scene, frameCount ); // sende med sceneNr og scneptr

    qDebug()<<bossHpCount;


    //oppretter og tegner TUX  - Flyttes - chrban
    tux = new Figur();
    connect(tux,SIGNAL(gott_av_banen()),this,SLOT(setUp()));
    tux->setPos(10,520);
    tux->setFlag(QGraphicsItem::ItemIsFocusable);
    tux->setFocus();
    scene->addItem(tux);


    qDebug()<<"før HP";
    //lager HP
    hp = new Hp();
    hp->setPos(0,20);
    hp->setHp(hpCount);
    scene->addItem(hp);    
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
    QGraphicsTextItem* bossText = new QGraphicsTextItem();
    bossText->setPlainText("Final Score: "+QString::number(scoreCount));
    bossText->setDefaultTextColor(Qt::yellow);
    bossText->setFont(QFont("tahoma",20));
    bossText->setPos(330,325);
    scene->addItem(bossText);

    // Legg til Main Menu-knapp
    Button* menu = new Button(QString("Main Menu"));
    menu->setPos(300,400);
    connect(menu, SIGNAL(clicked()), this, SLOT(showMainMenu()));
    scene->addItem(menu);

    show();

    hpCount=3;
    scoreCount=0;
    frameCount=0;
    GV->setFrame(frameCount);
}

void game::showWinScreen(){
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

    // You Win!
    QGraphicsTextItem* winText = new QGraphicsTextItem();
    winText->setPlainText("You Win!"+QString::number(scoreCount));
    winText->setDefaultTextColor(Qt::yellow);
    winText->setFont(QFont("tahoma",20));
    winText->setPos(330,325);
    scene->addItem(winText);

    // Legg til Main Menu-knapp
    Button* menu = new Button(QString("Main Menu"));
    menu->setPos(300,400);
    connect(menu, SIGNAL(clicked()), this, SLOT(showMainMenu()));
    scene->addItem(menu);

    show();

    hpCount=3;
    scoreCount=0;
    frameCount=0;
    GV->setFrame(frameCount);
}


void game::showEditorScreen()
{
    setBackgroundBrush(QBrush(Qt::white));
    CourseCreator * CC = new CourseCreator;
    CC->drawGrid(scene);

}

void game::pickedUpLinus(){

}

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
    // create scene
    Q_UNUSED(parent);
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/new/img/rorStdbackground.png")));
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    //local var
    hpCount=3;
    scoreCount=0;
    frameCount = 0;
    requiredScoreCount=40;
    bossHpCount=3;
    paused=false;
}

void game::showMainMenu(){

    scene->clear();
    QGraphicsTextItem* title = new QGraphicsTextItem(QString("Tux goes postal!"));
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
    setBackgroundBrush(QBrush(QImage(":/new/img/rorStdbackground.png")));

    //create sun
    Sun * sun = new Sun(680,30);
    scene->addItem(sun);

    //lager score
    score = new Score();
    score->increase(scoreCount);
    scene->addItem(score);

    //HP
    hp = new Hp();
    hp->setPos(0,20);
    hp->setHp(hpCount);
    scene->addItem(hp);


    //frameNr
    GV = new GlobalVar();
    GV-> setFrame(frameCount);
    GV->setRequiredScore(requiredScoreCount);

    //Activate bossbattle
    if(scoreCount >= GV->getRequiredScore() ){
        setBackgroundBrush(QBrush(QImage(":/new/img/bossback.jpg")));
        score->setDefaultTextColor(Qt::white);
        hp->setDefaultTextColor(Qt::white);
        SB = new superboss(700,450);
        scene->addItem( SB );
        SB->setHealth(  bossHpCount );
        scene->removeItem(sun);
        frameCount = 1337;
        QGraphicsTextItem* bossText = new QGraphicsTextItem();
        bossText->setPlainText("Boss Battle!");
        bossText->setDefaultTextColor(Qt::yellow);
        bossText->setFont(QFont("tahoma",20));
        bossText->setPos(350,10);
        scene->addItem(bossText);
    }

    //Create Level
    LevelFactory * LF = new LevelFactory;
    LF->loadMap( scene, frameCount );


    //Create figure, add to scene
    tux = new Figur();
    connect(tux,SIGNAL(gott_av_banen()),this,SLOT(setUp()));
    tux->setPos(10,520);
    tux->setFlag(QGraphicsItem::ItemIsFocusable);
    tux->setFocus();
    scene->addItem(tux);




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

void game::pause()
{
    if(!paused)
    {
        QBrush male;
        male.setStyle(Qt::SolidPattern);
        male.setColor(Qt::black);
        pausePanel->setBrush(male);
        pausePanel->setOpacity(0.65);
        pauseText->setPlainText("PAUSE");
        pauseText->setDefaultTextColor(Qt::blue);
        pauseText->setFont(QFont("tahoma",90));
        pauseText->setPos(this->width()/2-pauseText->boundingRect().width()/2,this->height()/2-pauseText->boundingRect().width()/2);
        scene->addItem(pausePanel);
        scene->addItem(pauseText);
        paused = true;
    }
    else{
        scene->removeItem(pausePanel);
        scene->removeItem(pauseText);
        paused = false;

    }

}

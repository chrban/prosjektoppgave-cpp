#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "figur.h"
#include "score.h"
#include "hp.h"
//#include "levelfactory.h"
#include "globalvar.h"
#include "superboss.h"



class game: public QGraphicsView{
    Q_OBJECT
public:
    game(QWidget * parent=0);
    QGraphicsScene * scene;
    Figur * tux;
    Score * score;
    Hp * hp;
    GlobalVar * GV;
    CourseCreator * CC;
    superboss * SB;
    QGraphicsRectItem* pausePanel = new QGraphicsRectItem(0,0,800,600);
    QGraphicsTextItem* pauseText = new QGraphicsTextItem();


    int hpCount;
    int scoreCount;
    int frameCount;
    int requiredScoreCount;
    int bossHpCount;

public slots:
    void setUp();
    void showMainMenu();
    void showKillScreen();
    void showWinScreen();
    void pause();

private:
    bool paused;



};

#endif // GAME_H


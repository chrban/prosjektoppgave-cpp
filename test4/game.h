#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "score.h"
#include "hp.h"
#include "globalvar.h"
#include "superboss.h"
#include "figur.h"

//#include "enemy.h"
//#include <QTimer>
//#include <QGraphicsTextItem>
//#include <QGraphicsRectItem>
//#include <QGraphicsPixmapItem>
//#include <QFont>
//#include "levelfactory.h"
//#include <QBrush>
//#include <QImage>
//#include "button.h"
//#include "sun.h"
//#include <QPixmap>


class game: public QGraphicsView{
    Q_OBJECT
public:
    game(QWidget * parent=0);
    QGraphicsScene * scene;
    Figur * tux;
    Score * score;
    Hp * hp;
    GlobalVar * GV;
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


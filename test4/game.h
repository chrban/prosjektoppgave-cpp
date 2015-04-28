#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "figur.h"
#include "score.h"
#include "hp.h"
#include "levelfactory.h"


class game: public QGraphicsView{
    Q_OBJECT
public:
    game(QWidget * parent=0);
    QGraphicsScene * scene;
    Figur * tux;
    Score * score; //legger til score
    Hp * hp;
//    LevelFactory * lf;
    int hpCount;
    int scoreCount;
    int frameCount;

public slots:
    void setUp();
    void pickedUpLinus();
    void showMainMenu();
    void showKillScreen();
    void showSuperBoss();

private:
    int linusCount;

//    void pickedUpLinus();
//    void showMainMenu();

//private:
//    int linusCount;


};

#endif // GAME_H

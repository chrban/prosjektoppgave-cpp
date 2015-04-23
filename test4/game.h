#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "figur.h"
#include "score.h"
#include "hp.h"


class game: public QGraphicsView{
    Q_OBJECT
public:
    game(QWidget * parent=0);
    QGraphicsScene * scene;
    Figur * tux;
    Score * score; //legger til score
    Hp * hp;
    int hpCount;
    int scoreCount;

public slots:
    void setUp();
    void pickedUpLinus();
    void showMainMenu();

private:
    int linusCount;

//    void pickedUpLinus();
//    void showMainMenu();

//private:
//    int linusCount;


};

#endif // GAME_H

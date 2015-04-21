#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "myrect.h"


class game: public QGraphicsView{
    Q_OBJECT
public:
    game(QWidget * parent=0);
    QGraphicsScene * scene;
    myrect * tux;

public slots:
    void setUp();

};

#endif // GAME_H
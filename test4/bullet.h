#ifndef BULLET
#define BULLET

#include<QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include "game.h"
#include "hp.h"


class bullet :  public QObject ,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    bullet();
    Hp * hp;
    ~bullet();
public slots:
    void move();

};


#endif // BULLET


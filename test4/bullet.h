#ifndef BULLET
#define BULLET

#include<QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject>
#include "hp.h"


class bullet :  public QObject ,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    bullet();
    Hp * hp;
public slots:
    void move();

};


#endif // BULLET


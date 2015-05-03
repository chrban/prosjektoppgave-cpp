#ifndef ENEMY
#define ENEMY
#include "object.h"
#include <QList>
#include <QGraphicsRotation>
#include <QGraphicsTransform>
#include <QPropertyAnimation>


class enemy :  public Object{
    Q_OBJECT

public:
    enemy(int x, int y);
    ~enemy();

public slots:
    void move();

private:
    QTimer * m;
    QTimer * s;
    int count;
    bool direction;


};

#endif // ENEMY_H



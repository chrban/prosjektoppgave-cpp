#ifndef SUPERBOSS
#define SUPERBOSS
#include "object.h"
#include <QList>
#include <QGraphicsRotation>
#include <QGraphicsTransform>
#include <QPropertyAnimation>

class superboss :  public Object{
    Q_OBJECT

public:
    superboss(int x, int y);
    void decrease();
    void setHealth(int h);
    int getHealth();

public slots:
    void move();
    void shoot();
    void jump();
    void jumper();

private:
    QTimer * m;
    QTimer * s;
    QTimer * j;
    QTimer * jmpr;
    int health;
    int count;
    int jump_count;
    bool direction;
    bool horizontal_direction;
};

#endif // SUPERBOSS


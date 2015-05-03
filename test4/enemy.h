#ifndef ENEMY
#define ENEMY
#include "object.h"
#include <QList>
#include <QObject>
#include <QPixmap>
#include <QTimer>
//#include "game.h"

class enemy :  public Object{
    Q_OBJECT

public:
    enemy(int x, int y);

public slots:
    void move();

private:
    QTimer * m;
    QTimer * s;
    int count;
    bool direction;


};

#endif // ENEMY_H



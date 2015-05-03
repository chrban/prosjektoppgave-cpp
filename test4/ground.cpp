#include "ground.h"
#include <QGraphicsPixmapItem>

Ground::Ground(int x, int y){
    // trenger et bakkebilde
    setPixmap(QPixmap(":/images/ground2.png"));
    setPos(x,y);
}


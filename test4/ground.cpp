#include "ground.h"
#include <QGraphicsPixmapItem>

Ground::Ground(int x, int y){
    setPixmap(QPixmap(":/images/ground2.png"));
    setPos(x,y);
}


#include "ground.h"

Ground::Ground(int x, int y){
    setPixmap(QPixmap(":/images/ground2.png"));
    setPos(x,y);
}


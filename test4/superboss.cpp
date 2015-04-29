#include "superboss.h"
#include <QPixmap>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <QPoint>
#include <QObject>
#include <qmath.h>
#include "bullet.h"

superboss::superboss(int x, int y){
    // set graphics
    setPixmap(QPixmap(":/new/img/ironcat.png"));
    setPos(x,y);
    fps = new QTimer();
    count = 0;
    health = 3;
}

void superboss::animate(){

}

void superboss::shoot(){
    // Ish?
    bullet * b = new bullet();
    b->setPos(x,y);
    scene->addItem(b);
}

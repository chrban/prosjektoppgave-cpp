#include "superboss.h"
#include <QPixmap>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <QPoint>
#include <QObject>
#include <qmath.h>

superboss::superboss(QGraphicsItem * parent){
    Q_UNUSED(parent); //debugger?
// set graphics
setPixmap(QPixmap(":/new/img/ironcat.png"));

}

void superboss::move_forward(){

}

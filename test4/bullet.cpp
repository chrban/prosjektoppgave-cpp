#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo>
#include "figur.h"
#include "game.h"

extern game * g;

bullet::bullet(){
    setPixmap(QPixmap(":/images/projectile.gif"));
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

void bullet::move(){
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i = 0, n= colliding_items.size();i<n;i++){
        if(typeid(*(colliding_items[i]))==typeid(Figur)){
            g->hp->decrease();
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

    setPos(x()-10,y());
    if(pos().x() + pixmap().width() < 0){
        scene()->removeItem(this);
        delete this;
    }

}

bullet::~bullet(){}

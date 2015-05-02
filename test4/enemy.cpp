#include "enemy.h"
#include <QPixmap>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QDebug>
#include <stdlib.h> //rand()
#include <QObject>
#include <qmath.h>
#include "game.h"

extern game * g;

    enemy::enemy(int x, int y) {
    // set graphics
    setPixmap(QPixmap(":/new/img/javaenemy.png"));
    setPos(x,y);
    m = new QTimer();
    s = new QTimer();
    movements = true;
    count = 0;
    connect(m,SIGNAL(timeout()),this,SLOT(move()));
    m->start(1000);
}
    void enemy::move() {
        //*count++;
        s->start(100);

    if(count ==10){
        connect(s,SIGNAL(timeout()),this,SLOT(move()));
        movements=false;
    }
    else if(count ==0){
        connect(s,SIGNAL(timeout()),this,SLOT(move()));
        movements=true;
    }

    if(movements){
        setPos(x()-5,y());
        count++;
    }
    else{
        setPos(x()+5,y());
        count--;
        }
    }

/*void enemy::left(){
    setPos(x()-1,y());
}

void enemy::right(){
    setPos(x()+5,y());
}

*/

#include "enemy.h"
//extern game * g;

enemy::enemy(int x, int y) {
    // set graphics
    setPixmap(QPixmap(":/images/java1.png"));
    setPos(x,y);
    m = new QTimer();
   // s = new QTimer();
    direction = true;
    count = 0;
    connect(m,SIGNAL(timeout()),this,SLOT(move()));
    m->start(40);
}
void enemy::move() {
    if(count==10){
        setPixmap(QPixmap(":/images/java1.png"));
        direction=false;
    }
    else if(count == 7){
        setPixmap(QPixmap(":/images/java2.png"));
        setPos(x(),y()-2);
    }
    else if(count == 4){
        setPixmap(QPixmap(":/images/java3.png"));
        setPos(x(),y()+4);
    }
    else if(count == 2){
        setPixmap(QPixmap(":/images/java2.png"));
        setPos(x(),y()-2);
    }

    else if(count ==0){
        setPixmap(QPixmap(":/images/java1.png"));

        direction=true;
    }

    if(direction){
        setPos(x()-2,y());
        count++;
    }
    else{
        setPos(x()+2,y());
        count--;
        }
}

enemy::~enemy(){
    delete m;
}

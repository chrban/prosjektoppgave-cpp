#include "sun.h"
#



Sun::Sun(int x, int y)
{
    setPixmap(QPixmap(":/new/img/sun1.png"));
    setPos(x,y);
    turn = true;

    animate = new QTimer();
    connect(animate,SIGNAL(timeout()),this,SLOT(spinn()));
    animate->start(200);
}

void Sun::spinn()
{
    if(turn){
        setPixmap(QPixmap(":/new/img/sun2.png"));
        turn=false;
    }
    else{
        setPixmap(QPixmap(":/new/img/sun1.png"));
        turn = true;
    }
}

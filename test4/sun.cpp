#include "sun.h"
#



Sun::Sun(int x, int y)
{
    setPixmap(QPixmap(":/images/sun1.png"));
    setPos(x,y);
    turn = true;

    animate = new QTimer();
    connect(animate,SIGNAL(timeout()),this,SLOT(spinn()));
    animate->start(200);
}

void Sun::spinn()
{
    if(turn){
        setPixmap(QPixmap(":/images/sun2.png"));
        turn=false;
    }
    else{
        setPixmap(QPixmap(":/images/sun1.png"));
        turn = true;
    }
}

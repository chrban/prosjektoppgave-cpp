#include "linus.h"
#include <QTimer>

Linus::Linus(int x, int y)
{
    setPixmap(QPixmap(":/images/coin.png"));
    setPos(x,y);
    fps = new QTimer();
    count =0;
    up=true;
    connect(fps,SIGNAL(timeout()),this,SLOT(animate()));
    fps->start(35);
}

void Linus::animate()
{
    if(count ==5){
        up=false;
    }
    else if(count ==0){
        up=true;
    }


    if(up){
        setPos(x(),y()-1);
        count++;
    }
    else{
        setPos(x(),y()+1);
        count--;
    }
}

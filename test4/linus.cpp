#include "linus.h"
#include <QTimer>
#include <QDebug>

Linus::Linus(int x, int y)
{
    setPixmap(QPixmap(":/images/linus-torvalds.png"));
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
    /*
    qDebug()<<"linussnu";
    if(count == 5)
        count = 0;

    switch(count){
    case 0 : setPixmap(QPixmap(":/images/linus-torvalds.png"));
        break;
    case 1 : setPixmap(QPixmap(":/images/linus-torvalds2.png"));
        break;
    case 2 : setPixmap(QPixmap(":/images/linus-torvalds3.png"));
        break;
    case 3 : setPixmap(QPixmap(":/images/linus-torvalds4.png"));

    default : setPixmap(QPixmap(":/images/linus-torvalds4.png"));
    }
    count++;
    */
}

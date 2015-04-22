#include "box.h"
#include "boxfactory.h"
#include <stdlib.h>
#include <QGraphicsPixmapItem>
#include <QDebug>

using namespace std;


QGraphicsItem *boxFactory::mekk()
{
    int random_x = rand()%700;
    int random_y = 480;//(rand()%20) + 480;
    Box * box= new Box(random_x,random_y);
    return box;
}

// mekker bakke
QGraphicsItem * boxFactory::makeGround(){
    int yesno=rand()%10;


    i+=30;
    if(yesno!=1){
        Box * box= new Box(i,550);

        return box;
    }
    Box * box2= new Box(i,400);
    box2->setPixmap(QPixmap(":/new/img/BOKSnei.png"));
    return box2;

}

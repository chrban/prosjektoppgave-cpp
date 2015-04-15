#include <stdlib.h>
#include <QGraphicsRectItem>
#include "rectfac.h"


using namespace std;

// skal senere bli factory for engendefinert hinder/objekt/div
QGraphicsRectItem * rectFac::mekk()
{
    int random_x = rand()%700;
    int random_y = (rand()%300) + 200;

    // hinderItem
    QGraphicsRectItem * ny = new QGraphicsRectItem();
    ny->setRect(random_x,random_y,100,20);
    return ny;

}

#include "box.h"
#include "boxfactory.h"
#include <stdlib.h>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <utility>
#include <map>

using namespace std;



QGraphicsItem *boxFactory::mekk()
{
    int random_x = rand()%700;
    int random_y = 480;//(rand()%20) + 480;
    Box * box= new Box(random_x,random_y);
    return box;
}

QGraphicsItem *boxFactory::mekk(int x,int y){
    Box * box= new Box(x*BOX_WIDTH,y*BOX_HEIGHT);
    return box;
}

boxFactory::~boxFactory(){}

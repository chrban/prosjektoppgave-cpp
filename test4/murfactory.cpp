#include "mur.h"
#include "murfactory.h"
#include <stdlib.h>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include <utility>
#include <map>

using namespace std;

QGraphicsItem * MurFactory::mekk()
{
    int random_x = rand()%700;
    int random_y = 480;//(rand()%20) + 480;
    Mur * mur = new Mur(random_x,random_y);
    return mur;
}

QGraphicsItem * MurFactory::mekk(int x,int y){
    Mur * mur= new Mur(x*MUR_WIDTH,y*MUR_HEIGHT);
    return mur;
}


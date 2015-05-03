#include "murfactory.h"

using namespace std;

QGraphicsItem * MurFactory::mekk()
{
    int random_x = rand()%700;
    int random_y = 480;
    Mur * mur = new Mur(random_x,random_y);
    return mur;
}

QGraphicsItem * MurFactory::mekk(int x,int y){
    Mur * mur= new Mur(x*MUR_WIDTH,y*MUR_HEIGHT);
    return mur;
}

MurFactory::~MurFactory(){}

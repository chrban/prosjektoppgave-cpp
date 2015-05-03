#include "cloudfactory.h"




QGraphicsItem * CloudFactory::mekk(){
    int random_x = rand()%700;
    int random_y = rand()%200;
    Cloud * cloud= new Cloud(random_x,random_y);
    return cloud;
}
QGraphicsItem * CloudFactory::mekk(int x, int y){

    Cloud * cloud = new Cloud(x,y);
    return cloud;
}

CloudFactory::~CloudFactory(){}


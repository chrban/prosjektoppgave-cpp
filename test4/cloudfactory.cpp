#include "cloudfactory.h"
#include "cloud.h"



QGraphicsItem * CloudFactory::mekk(){
    int random_x = rand()%700;
    int random_y = rand()%250;
    Cloud * cloud= new Cloud(random_x,random_y);
    return cloud;
}

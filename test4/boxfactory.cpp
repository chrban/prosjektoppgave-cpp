#include "box.h"
#include "boxfactory.h"
#include <stdlib.h>

using namespace std;


QGraphicsItem *boxFactory::mekk()
{
    int random_x = rand()%700;
    int random_y = (rand()%300) + 200;
    Box * box= new Box(random_x,random_y);
    return box;
}

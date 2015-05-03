#include "linusfactory.h"


QGraphicsItem *LinusFactory::mekk()
{
    int random = rand()%700;
    Linus * linus = new Linus(random, 512);
    return linus;
}

QGraphicsItem *LinusFactory::mekk(int x,int y)
{

    Linus * linus = new Linus(x,y);
    return linus;
}

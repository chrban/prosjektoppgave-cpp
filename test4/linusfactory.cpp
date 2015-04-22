#include "linusfactory.h"
#include "linus.h"
#include <stdlib.h>


QGraphicsItem *LinusFactory::mekk()
{
    int random = rand()%700;
    Linus * linus = new Linus(random, 512);
    return linus;
}

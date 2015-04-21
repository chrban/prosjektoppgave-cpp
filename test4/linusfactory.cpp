#include "linusfactory.h"
#include "linus.h"
#include <stdlib.h>


QGraphicsItem *LinusFactory::mekk()
{
    int random = rand()%800;
    Linus * linus = new Linus(random, 500);
    return linus;
}

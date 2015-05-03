#ifndef LINUSFACTORY
#define LINUSFACTORY
#include "linus.h"
#include <stdlib.h>
#include <abstractfac.h>

class LinusFactory : public abstractFac{

public:
    LinusFactory(){}
    QGraphicsItem * mekk();
    QGraphicsItem * mekk(int x,int y);

};

#endif // LINUSFACTORY


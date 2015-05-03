#ifndef GROUNDFACTORY
#define GROUNDFACTORY
#include "ground.h"
#include <abstractfac.h>

class GroundFactory : public abstractFac{

public:
    GroundFactory():i(-50){}
    ~GroundFactory();
    QGraphicsItem * mekk();
    QGraphicsItem * mekk(int x, int);

private:
    int i;
};

#endif // GROUNDFACTORY


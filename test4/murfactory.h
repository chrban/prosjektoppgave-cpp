#ifndef MURFACTORY
#define MURFACTORY

#include <stdlib.h>
#include "mur.h"
#include <abstractfac.h>

class MurFactory : public abstractFac{

public:
    MurFactory();
    ~MurFactory();
    QGraphicsItem * mekk();
    QGraphicsItem *mekk(int x,int y);
private:
    static const int MUR_WIDTH=32;
    static const int MUR_HEIGHT=25;
};


#endif // MURFACTORY


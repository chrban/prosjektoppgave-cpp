#ifndef CLOUDFACTORY
#define CLOUDFACTORY
#include <abstractfac.h>
#include "cloud.h"

class CloudFactory : public abstractFac{

public:
    QGraphicsItem * mekk();
    QGraphicsItem * mekk(int x, int y);
};
#endif // CLOUDFACTORY


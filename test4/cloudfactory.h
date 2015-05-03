#ifndef CLOUDFACTORY
#define CLOUDFACTORY
#include <abstractfac.h>

class CloudFactory : public abstractFac{

public:
    QGraphicsItem * mekk();
    QGraphicsItem * mekk(int x, int y);
    ~CloudFactory();
};
#endif // CLOUDFACTORY


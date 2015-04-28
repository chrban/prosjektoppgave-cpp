#ifndef GROUNDFACTORY
#define GROUNDFACTORY

#include <QGraphicsRectItem>
#include <abstractfac.h>

class GroundFactory : public abstractFac{

public:
    GroundFactory():i(-50){}
    QGraphicsItem * mekk();
private:
    int i;
};

#endif // GROUNDFACTORY


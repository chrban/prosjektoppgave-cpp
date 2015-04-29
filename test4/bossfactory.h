#ifndef BOSSFACTORY_H
#define BOSSFACTORY_H

#include <QGraphicsRectItem>
#include <abstractfac.h>
#include "superboss.h"

class BossFactory : public abstractFac{

public:
    BossFactory(){}
    QGraphicsItem * mekk(int x,int y);
    QGraphicsItem * mekk();

};

#endif // BOSSFACTORY_H

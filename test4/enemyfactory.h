#ifndef ENEMYFACTORY
#define ENEMYFACTORY
#include <abstractfac.h>
#include "enemy.h"


class EnemyFactory : public abstractFac{

public:
    EnemyFactory(){}
    QGraphicsItem * mekk();
    QGraphicsItem * mekk(int x,int y);

};

#endif // ENEMYFACTORY


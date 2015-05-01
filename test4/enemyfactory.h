#ifndef ENEMYFACTORY
#define ENEMYFACTORY

#include <QGraphicsRectItem>
#include <abstractfac.h>

class EnemyFactory : public abstractFac{

public:
    EnemyFactory(){}
    QGraphicsItem * mekk();
    QGraphicsItem * mekk(int x,int y);

};

#endif // ENEMYFACTORY


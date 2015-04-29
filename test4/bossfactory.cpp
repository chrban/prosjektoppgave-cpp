#include <stdlib.h>
#include "bossfactory.h"
#include "superboss.h"
#include <QGraphicsItem>

QGraphicsItem *BossFactory::mekk(int x, int y){
    superboss * boss = new superboss(x,y);
    return boss;
}

#include "enemyfactory.h"
#include "enemy.h"
#include <stdlib.h>


QGraphicsItem *EnemyFactory::mekk()
{
    int random = rand()%700;
    enemy * Enemy = new enemy(random, 512);
    return Enemy;
}

QGraphicsItem *EnemyFactory::mekk(int x,int y)
{

    enemy * Enemy = new enemy(x,y);
    return Enemy;
}

EnemyFactory::~EnemyFactory(){
    delete Enemy;
}

#ifndef LEVELFACTORY
#define LEVELFACTORY
#include <utility>
#include "game.h"
#include "boxfactory.h"
#include "linusfactory.h"
#include "groundfactory.h"
#include "cloudfactory.h"
#include "globalvar.h"
#include "enemyfactory.h"
#include "murfactory.h"

#include <vector>

class LevelFactory{

public:
    game * GP;
    boxFactory * BF;
    LinusFactory * LF;
    GroundFactory * GF;
    CloudFactory * CF;
    EnemyFactory * EF;
    MurFactory * MF;
    LevelFactory();
    ~LevelFactory();
    void loadMap(QGraphicsScene* scene, int f);

private:



};

#endif // LEVELFACTORY


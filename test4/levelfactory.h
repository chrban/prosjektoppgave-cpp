#ifndef LEVELFACTORY
#define LEVELFACTORY
#include <utility>
#include "game.h"
#include "boxfactory.h"
#include "linusfactory.h"
#include "groundfactory.h"
#include "cloudfactory.h"
#include "bossfactory.h"
#include "globalvar.h"

#include <vector>

class LevelFactory{

public:
    game * GP;
    boxFactory * BF;
    LinusFactory * LF;
    GroundFactory * GF;
    CloudFactory * CF;
    BossFactory * SBF;
    LevelFactory();
    void loadMap(QGraphicsScene* scene, int f);

private:



};

#endif // LEVELFACTORY


#include "groundfactory.h"
#include "ground.h"
QGraphicsItem * GroundFactory::mekk(){


    int yesno=rand()%10;
    i+=30;
    if(yesno!=1){
        Ground * ground= new Ground(i,550);

        return ground;
    }
    Ground * seethrough= new Ground(i,400);
    seethrough->setPixmap(QPixmap(":/new/img/BOKSnei.png"));
    return seethrough;
}

#include "groundfactory.h"
#include "ground.h"
QGraphicsItem * GroundFactory::mekk(){


    int yesno=rand()%10;
    i+=50;
    if(yesno!=1){
        Ground * ground= new Ground(i,550);

        return ground;
    }


    Ground * seethrough= new Ground(i,400);
    seethrough->setPixmap(QPixmap(":/images/BOKSnei.png"));
    return seethrough;
}

QGraphicsItem * GroundFactory::mekk(int x, int y)
{
    Ground * ground = new Ground(x,y);

    return ground;

}




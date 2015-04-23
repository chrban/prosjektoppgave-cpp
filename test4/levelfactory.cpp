#include <vector>
#include "levelfactory.h"
#include <QDebug>


int LevelFactory::x[20]={100,133,166,199,232,265,298,331,364,397,460,400,600,600,600,600,600,166,460,400};
int LevelFactory::y[20]={420,420,420,420,420,420,420,420,420,420,400,350,525,500,475,450,400,412,362,312};

LevelFactory::LevelFactory() : count(0)
{



}

int LevelFactory::getNextY()
{
    qDebug()<<count<<"her";
    qDebug()<<y[count];
    return y[count++];
}

int LevelFactory::getNextX()
{
    qDebug()<<x[count];
    qDebug()<<count;
    return x[count];

}



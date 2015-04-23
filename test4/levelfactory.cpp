#include <vector>
#include "levelfactory.h"
#include <QDebug>


int LevelFactory::x[20]={100,133,166,199,232,265,298,331,364,397,460,400,600,600,600,600,600,166,460,400};
int LevelFactory::y[20]={480,480,480,480,480,480,480,480,480,480,450,380,525,500,475,450,425,442,412,342};

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



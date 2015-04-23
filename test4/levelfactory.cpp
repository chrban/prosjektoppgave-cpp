#include <vector>
#include "levelfactory.h"
#include <QDebug>


int LevelFactory::x[4]={100,200,300,400};
int LevelFactory::y[4]={400,400,400,400};

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



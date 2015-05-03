#include "cloud.h"
#include <QTimer>
#include <stdlib.h>
#include <QDebug>


using namespace std;


Cloud::Cloud(int x, int y)
{
    setPixmap(QPixmap(":/images/large_cloud.png"));
    setPos(x,y);

    animate = new QTimer();
    connect(animate,SIGNAL(timeout()),this,SLOT(move()));

    int r = (rand()%40)+200;
    if(r>220)
        setPixmap(QPixmap(":/images/small_cloud.png"));

    int direction = rand()%2;
    left = false;

    if(direction==1)
        left=true;

    setZValue(-1);

    animate->start(r);
}

void Cloud::move()
{
    if(left)
        setPos(x()-1,y());
    else
        setPos(x()+1,y());
}

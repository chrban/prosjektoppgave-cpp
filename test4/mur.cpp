#include <QGraphicsPixmapItem>
#include "mur.h"

using namespace std;


Mur::Mur(int x, int y)
{
    setPixmap(QPixmap(":/images/mur.png"));
    setPos(x,y);
}


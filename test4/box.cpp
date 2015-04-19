#include <QGraphicsPixmapItem>
#include "box.h"

using namespace std;


Box::Box(int x, int y)
{
    setPixmap(QPixmap(":/new/img/BOKS.png"));
    setPos(x,y);
}

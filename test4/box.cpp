#include <QGraphicsPixmapItem>
#include "box.h"

using namespace std;


Box::Box(int x, int y)
{
    setPixmap(QPixmap(":/images/BOKS.png"));
    setPos(x,y);
}

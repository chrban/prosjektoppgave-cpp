#ifndef BOXFACTORY
#define BOXFACTORY
#include "box.h"

#include <QGraphicsRectItem>
#include <abstractfac.h>

class boxFactory : public abstractFac{

public:
    boxFactory();
    QGraphicsItem * mekk();
    QGraphicsItem *mekk(int x,int y);
private:
    static const int BOX_WIDTH=32;
    static const int BOX_HEIGHT=25;
};

#endif // BOXFACTORY


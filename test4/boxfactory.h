#ifndef BOXFACTORY
#define BOXFACTORY

#include <QGraphicsRectItem>
#include <abstractfac.h>

class boxFactory : public abstractFac{

public:
    boxFactory();
    QGraphicsItem * mekk();
    QGraphicsItem *mekk(int x,int y);
};

#endif // BOXFACTORY


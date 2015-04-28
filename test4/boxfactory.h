#ifndef BOXFACTORY
#define BOXFACTORY

#include <QGraphicsRectItem>
#include <abstractfac.h>

class boxFactory : public abstractFac{

public:
    boxFactory():i(-33){}
    QGraphicsItem * mekk();
    QGraphicsItem * mekk(int x,int y);
    QGraphicsItem * makeGround();
private:
    int i;
};

#endif // BOXFACTORY


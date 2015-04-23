#ifndef LINUSFACTORY
#define LINUSFACTORY

#include <QGraphicsRectItem>
#include <abstractfac.h>

class LinusFactory : public abstractFac{

public:
    LinusFactory(){}
    QGraphicsItem * mekk();
    QGraphicsItem * mekk(int x,int y);

};

#endif // LINUSFACTORY


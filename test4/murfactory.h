#ifndef MURFACTORY
#define MURFACTORY

#include <QGraphicsRectItem>
#include <abstractfac.h>

class MurFactory : public abstractFac{

public:
    MurFactory();
    QGraphicsItem * mekk();
    QGraphicsItem *mekk(int x,int y);
private:
    static const int MUR_WIDTH=32;
    static const int MUR_HEIGHT=25;
};


#endif // MURFACTORY

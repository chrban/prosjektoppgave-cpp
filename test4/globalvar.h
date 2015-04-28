#ifndef GLOBALVAR
#define GLOBALVAR
//#include "game.h"


class GlobalVar{
public:
    int getFrame();
    void setFrame(int f);
    void increaseFrame();
    void decreaseFrame();
private:
    int frame;

};


#endif // GLOBALVAR



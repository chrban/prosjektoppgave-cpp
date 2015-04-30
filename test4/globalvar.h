#ifndef GLOBALVAR
#define GLOBALVAR
//#include "game.h"


class GlobalVar{
public:
    //framenumber
    int getFrame();
    void setFrame(int f);
    void increaseFrame();
    void decreaseFrame();

    //requiredScore to reach boss-level
    int getRequiredScore();
    void setRequiredScore(int r);
    GlobalVar();
private:
    int frame;
    int requiredScore;

};


#endif // GLOBALVAR



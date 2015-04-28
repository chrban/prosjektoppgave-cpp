#include "globalvar.h"
#include "game.h"


extern game * g;
int GlobalVar::getFrame()
{
    return frame;
}

void GlobalVar::setFrame(int f)
{
    frame = f;
}

void GlobalVar::increaseFrame(){

    frame++;
    g->frameCount=frame;
}

void GlobalVar::decreaseFrame(){
    frame--;
    g->frameCount=frame;
}




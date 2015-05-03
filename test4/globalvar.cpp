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


GlobalVar::GlobalVar()
{
    requiredScore = 40;
}

int GlobalVar::getRequiredScore()
{
    return requiredScore;
}

void GlobalVar::setRequiredScore(int r)
{
    g->requiredScoreCount=r;
    requiredScore = r;
}





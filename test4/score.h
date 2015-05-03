#ifndef SCORE
#define SCORE
#include <QFont>
#include <QGraphicsTextItem>
#include "globalvar.h"

class Score: public QGraphicsTextItem {

public:
    Score(QGraphicsItem * parent = 0);
    GlobalVar * gv;
    void increase(int inc);
    void increase();
    int getScore();
    ~Score();

private:
    int score;
};

#endif // SCORE



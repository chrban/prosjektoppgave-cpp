#ifndef SCORE
#define SCORE

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem {
public:
    Score(QGraphicsItem * parent = 0);
    void increase(int inc);
    void increase();
    int getScore();

private:
    int score;
};

#endif // SCORE



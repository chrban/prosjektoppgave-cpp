#include "score.h"
#include "game.h"


extern game * g;

Score::Score(QGraphicsItem * parent): QGraphicsTextItem(parent) {
    score = 0;

    //tekst
    setPlainText(QString("Score: ") + QString::number(score)); //Score: 0
    setDefaultTextColor(Qt::black); //farge
    setFont(QFont("tahoma",16));

}

void Score::increase(int inc) {
    score=score+inc;
    g->scoreCount=score;
    //tekst
    setPlainText(QString("Score: ") + QString::number(score));
}

void Score::increase() {
    score++;
    g->scoreCount=score;
    //tekst
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore() {
    return score;
}

Score::~Score(){}

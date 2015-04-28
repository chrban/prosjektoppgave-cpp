#include "score.h"
#include "game.h"
#include <QFont>
#include <QDebug>

extern game * g;

Score::Score(QGraphicsItem * parent): QGraphicsTextItem(parent) {
    score = 41;

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
    if(score >= 42)
        g->showSuperBoss();

}

void Score::increase() {
    score++;
    //tekst
    setPlainText(QString("Score: ") + QString::number(score));
    g->scoreCount=score;
    if(score >= 42)
        g->showSuperBoss();

}

int Score::getScore() {
    return score;
}

#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem * parent): QGraphicsTextItem(parent) {
    //score til 0
    score = 0;

    //tekst
    setPlainText(QString("Score: ") + QString::number(score)); //Score: 0
    setDefaultTextColor(Qt::black); //farge
    setFont(QFont("tahoma",16));

}

void Score::increase() {
    score++;
    //tekst
    setPlainText(QString("Score: ") + QString::number(score)); //Score: 0

}

int Score::getScore() {
    return score;
}

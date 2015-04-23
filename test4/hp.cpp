#include "hp.h"
#include <QFont>

Hp::Hp(QGraphicsItem * parent): QGraphicsTextItem(parent) {
    //Hp til 0
    hp = 3;

    //tekst
    setPlainText(QString("HP: ") + QString::number(hp)); //Hp: 3
    setDefaultTextColor(Qt::black); //farge
    setFont(QFont("tahoma",16));

}

void Hp::decrease() {
    hp--;
    //tekst
    setPlainText(QString("HP: ") + QString::number(hp));

}

int Hp::getHp() {
    return hp;
}


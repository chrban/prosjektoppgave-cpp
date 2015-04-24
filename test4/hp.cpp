#include "hp.h"
#include "game.h"
#include <QFont>

extern game * g;

Hp::Hp(QGraphicsItem * parent): QGraphicsTextItem(parent) {
    //tekst

    hp = g->hpCount;

    setPlainText(QString("HP: ") + QString::number(hp)); //Hp: 3
    setDefaultTextColor(Qt::black); //farge
    setFont(QFont("tahoma",16));
}

void Hp::increase() {
    hp++;
    g->hpCount=hp;
    //tekst
    setPlainText(QString("HP: ") + QString::number(hp));
}

void Hp::decrease() {
    hp--;
    g->hpCount=hp;
    //tekst
    setPlainText(QString("HP: ") + QString::number(hp));
    if(hp <= 0)
        g->showKillScreen();
}

void Hp::setHp(int h){
    hp=h;
}

int Hp::getHp() {
    return hp;
}


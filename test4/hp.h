#ifndef HP_H
#define HP_H

#include <QGraphicsTextItem>

class Hp: public QGraphicsTextItem {
public:
    Hp(QGraphicsItem * parent = 0);
    void increase();
    void decrease();
    void setHp(int h);
    int getHp();

private:
    int hp;
};

#endif // HP_H



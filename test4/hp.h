#ifndef HP_H
#define HP_H
#include <QFont>
#include <QGraphicsTextItem>

class Hp: public QGraphicsTextItem {
public:
    Hp(QGraphicsItem * parent = 0);
    void increase();
    void decrease();
    void setHp(int h);
    int getHp();
    ~Hp();

private:
    int hp;
};

#endif // HP_H



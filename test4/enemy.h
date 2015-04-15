#ifndef ENEMY
#define ENEMY

#include<QGraphicsRectItem>
#include <QObject>


class enemy :  public QObject ,public QGraphicsRectItem{
    Q_OBJECT
public:
    enemy();
public slots:
    void move();

};

#endif // ENEMY


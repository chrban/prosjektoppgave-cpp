#ifndef ENEMY
#define ENEMY
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList> //liste med elementer
#include <QPointF>


class enemy :  public QObject ,public QGraphicsPixmapItem {
    Q_OBJECT

public:
    enemy(QGraphicsItem * parent=0);
    void rotateToPoint(QPointF p);

public slots:
    void move_forward();

private:
    QList<QPointF> points;
    QPointF destination;
    int point_index;





//public slots:
    //void move();

};

#endif // ENEMY_H


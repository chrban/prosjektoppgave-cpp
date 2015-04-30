#ifndef ENEMY
#define ENEMY
#include <QGraphicsPixmapItem>
#include <QObject>


class enemy :  public QObject ,public QGraphicsPixmapItem {
    Q_OBJECT

public:
    enemy(int x, int y);

public slots:
    void move();
    void animate();


};

#endif // ENEMY_H


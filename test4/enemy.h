#ifndef ENEMY
#define ENEMY
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QGraphicsRotation>
#include <QGraphicsTransform>
#include <QPropertyAnimation>


class enemy :  public QObject ,public QGraphicsPixmapItem {
    Q_OBJECT

public:
    enemy(int x, int y);

public slots:
    void move();

private:
    QTimer * m;
    QTimer * s;
    int count;
    bool movements;


};

#endif // ENEMY_H



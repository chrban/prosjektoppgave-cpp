#ifndef SUPERBOSS
#define SUPERBOSS
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QGraphicsRotation>
#include <QGraphicsTransform>
#include <QPropertyAnimation>

class superboss :  public QObject ,public QGraphicsPixmapItem {
    Q_OBJECT

public:
    superboss(int x, int y);
    void decrease();
    void setHealth(int h);

public slots:
    void move();
    void shoot();

private:
    QTimer * m;
    QTimer * s;
    int health;
    int count;
    bool movements;
};

#endif // SUPERBOSS


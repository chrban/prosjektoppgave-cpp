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

public slots:
    void move();
    void upLeft();
    void upRight();
    void down();

private:
    QTimer * m;
    QTimer * s;
    void shoot();
    int health;
    int count;
};

#endif // SUPERBOSS


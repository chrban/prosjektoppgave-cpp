#ifndef SUPERBOSS
#define SUPERBOSS
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList> //liste med elementer
#include <QPointF>

class superboss :  public QObject ,public QGraphicsPixmapItem {
    Q_OBJECT

public:
    superboss(QGraphicsItem * parent=0);
    void rotateToPoint(QPointF p);

public slots:
    void move_forward();

private:
    QList<QPointF> points;
    QPointF destination;
    int point_index;
    int health;
};

#endif // SUPERBOSS


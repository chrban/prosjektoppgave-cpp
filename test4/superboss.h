#ifndef SUPERBOSS
#define SUPERBOSS
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList> //liste med elementer
#include <QPointF>

class superboss :  public QObject ,public QGraphicsPixmapItem {
    Q_OBJECT

public:
    superboss(int x, int y);
    void rotateToPoint(QPointF p);

public slots:
    void animate();

private:
    QList<QPointF> points;
    QPointF destination;
    QTimer * fps;
    int point_index;
    int health;
    int count;
};

#endif // SUPERBOSS


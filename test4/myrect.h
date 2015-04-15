#ifndef MYRECT
#define MYRECT
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class myrect:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    myrect();
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
    void jump();

private:
    bool falling;
    bool jumping;
    int velocity;
    QTimer * timer_up;


};


#endif // MYRECT


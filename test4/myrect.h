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
    void walk();

signals:
    void nyttBrett();
private:
    bool falling;
    bool jumping;
    bool walking;
    bool left;
    bool right;
    int velocity;
    int walked;
    int timer;
    QTimer * timer_up;
    QTimer * timerWalk;

    void updateImg();



};


#endif // MYRECT


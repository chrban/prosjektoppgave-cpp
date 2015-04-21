#ifndef MYRECT
#define MYRECT
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class Figur:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Figur();
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
    QTimer * timer_for_jump;
    QTimer * timer_for_walk;

    void updateImg();



};


#endif // MYRECT


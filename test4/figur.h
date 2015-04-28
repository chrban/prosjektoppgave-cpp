#ifndef MYRECT
#define MYRECT
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include "levelfactory.h"

class Figur:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Figur();
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *event);
        LevelFactory * lf;
public slots:
    void spawn();
    void jump();
    void walk();

signals:
    void gott_av_banen();
private:
    bool falling;
    bool jumping;
    bool walking;
    bool left;
    bool right;
    int velocity;
    int walked;
    int timer;
    int superspeed;
    QTimer * timer_for_jump;
    QTimer * timer_for_walk;

    void updateImg();



};


#endif // MYRECT


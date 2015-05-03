#ifndef FIGUR_H
#define FIGUR_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QList>
#include "globalvar.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QTimer>
#include "enemy.h" //trenger for typeId
#include "linus.h" //trenger for typeId





class Figur:public Object{
    Q_OBJECT
public:
    Figur();
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *event);
    ~Figur();
public slots:
    //void spawn();
    void jump();
    void walk();
    void scanner();

signals:
    void gott_av_banen();
    void startScan();
    void pauseSignal();

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
    QTimer * timer_scanner;

    void updateImg();



};


#endif // FIGUR_H

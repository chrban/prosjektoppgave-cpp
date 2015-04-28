#include "enemy.h"
#include <QPixmap>
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <QPoint>
#include <QObject>
#include <qmath.h>

    enemy::enemy(QGraphicsItem * parent){
    Q_UNUSED(parent); //debugger?
    // set graphics
    setPixmap(QPixmap(":/new/img/boss.png"));

    //points - nedover-høyre så høyre
    points << QPointF(10,520) << QPointF(10,520); //400,200
    point_index = 0;
    destination = points[0];

    //timer to move_forward
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_forward()));
    timer->start(150); //millisekunder

}

void enemy::rotateToPoint(QPointF p) {
    QLineF ln(pos(),p);
    setRotation(-1 * ln.angle());
}

void enemy::move_forward(){
    // if close to dest, rotate to next dest
    QLineF ln(pos(),destination);
    if (ln.length() < 5){
        point_index++;
        destination = points[point_index];
        rotateToPoint(destination);
    }

    // move enemy forward at current angle
    int STEP_SIZE = 5;
    double theta = rotation(); // degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);

}

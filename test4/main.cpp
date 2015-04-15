#include <QGraphicsScene>
#include "myrect.h"
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene * scene = new QGraphicsScene();
    myrect* rect = new myrect();
    QGraphicsRectItem* bakke = new QGraphicsRectItem();
    QGraphicsRectItem* dings = new QGraphicsRectItem();
    //rect->setRect(0,0,100,100);

    scene->addItem(rect);


    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    QGraphicsView * view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    bakke->setRect(-1,view->height()-30,800,31);
    dings->setRect(400,400,100,10);
    scene->addItem(bakke);
    scene->addItem(dings);

    rect->setPos(view->width()/2,view->height() - 30-50);


   /* QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),rect,SLOT(spawn()));
    timer->start(2000);
*/
    return a.exec();
}

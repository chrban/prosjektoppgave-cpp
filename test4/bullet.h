#ifndef BULLET
#define BULLET

#include<QGraphicsRectItem>
#include <QObject>


class bullet :  public QObject ,public QGraphicsRectItem{
    Q_OBJECT
public:
    bullet();
public slots:
    void move();

};


#endif // BULLET


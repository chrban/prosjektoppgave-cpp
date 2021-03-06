#include "button.h"

Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){
    setRect(0,0,200,25);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    setBrush(brush);

    text = new QGraphicsTextItem(name, this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos, yPos);

    setAcceptHoverEvents(true);
}

Button::Button(){}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    Q_UNUSED(event); //debugger?
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    Q_UNUSED(event); //debugger?
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::lightGray);
    setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    Q_UNUSED(event); //debugger?
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    setBrush(brush);
}

Button::~Button(){
    delete text;
}

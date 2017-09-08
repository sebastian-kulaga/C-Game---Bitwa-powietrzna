#include <QGraphicsTextItem>
#include <QBrush>
#include <przycisk.h>
Przycisk::Przycisk(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){
    // narysuj kwadrat
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);

    // text
    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);

    // reaguje na najechanie
    setAcceptHoverEvents(true);
}

void Przycisk::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
}

void Przycisk::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    // change color to cyan
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
}

void Przycisk::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    // change color to dark cyan
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
}

#ifndef PLAYERPLANE_H
#define PLAYERPLANE_H

#include "flightvehicle.h"
#include "bulletfactory.h"

class PlayerPlane : public FlightVehicle
{
public:
    PlayerPlane(qreal blood, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~PlayerPlane();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int name() const;
    void advance(int);
    void posLost();
    void doCollide();
    void fall();
    void strike();
    void shoot();
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
private:
    qreal m_bomb, m_bullet;//必杀技 & 子弹形态
    bool W, A, S, D, bomb;
};

#endif // PLAYERPLANE_H

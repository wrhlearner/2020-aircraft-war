#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include "flightvehicle.h"
#include "bulletfactory.h"

class EnemyPlane : public FlightVehicle
{
public:
    EnemyPlane(qreal angle, qreal blood, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~EnemyPlane();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int name() const;
    void posLost();
    void strike();
protected:
    qreal m_angle, x_speed, y_speed;
};

#endif // ENEMYPLANE_H

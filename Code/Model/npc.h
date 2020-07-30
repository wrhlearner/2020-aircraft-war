#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include "aircraft.h"

class Npc : public Aircraft
{
public:
    Npc(qreal blood, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~Npc();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int getName() const;
    void InvalidPosition();
protected:
    qreal x_speed, y_speed;
};

#endif // ENEMYPLANE_H

#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include "bullet.h"

class NpcBullet : public Bullet
{
public:
    NpcBullet(qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~NpcBullet();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int getName() const;
    void InvalidPosition();
    void advance(int);
    void Collision();
    void BreakDown();
};

#endif // ENEMYBULLET_H

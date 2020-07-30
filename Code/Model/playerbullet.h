#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H

#include "bullet.h"

class PlayerBullet : public Bullet
{
public:
    PlayerBullet(qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~PlayerBullet();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int getName() const;
    void advance(int);
    void InvalidPosition();
    void Collision();
    void BreakDown();
};

#endif // PLAYERBULLET_H

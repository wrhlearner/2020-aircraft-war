#ifndef PLAYERBOMB_H
#define PLAYERBOMB_H

#include "bullet.h"
#include "npcbullet.h"

class Bomb : public Bullet
{
public:
    Bomb(qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~Bomb();
    QPainterPath shape() const;
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int getName() const;
    void advance(int);
    void InvalidPosition();
    void Collision();
    void BreakDown();
};

#endif // BOMB_H

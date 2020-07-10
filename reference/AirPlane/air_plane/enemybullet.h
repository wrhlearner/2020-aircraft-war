#ifndef ENEMYBULLET_H
#define ENEMYBULLET_H

#include "bullet.h"
#include <math.h>

#define ROTATE 57.26

class EnemyBullet : public Bullet
{
public:
    EnemyBullet(qreal angle, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~EnemyBullet();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int name() const;
    void posLost();
    void advance(int);
    void doCollide();
    void fall();
};

#endif // ENEMYBULLET_H

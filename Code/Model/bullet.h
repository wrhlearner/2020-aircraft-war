#ifndef BULLET_H
#define BULLET_H

#include "flyingobject.h"
#include "flyertypecast.h"

class Bullet : public FlyingObject
{
public:
    Bullet(qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    virtual ~Bullet(){}
protected:
    qreal xSpeed, ySpeed;
};

#endif // BULLET_H

#include "bullet.h"

Bullet::Bullet(qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent)
    :FlyingObject(w, h, speed, pixs, scene, parent), xSpeed(0), ySpeed(m_speed) {}

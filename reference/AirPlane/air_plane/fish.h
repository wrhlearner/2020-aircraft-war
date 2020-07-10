#ifndef FISH_H
#define FISH_H

#include "enemyplane.h"
#include "randomizer.h"

class Fish : public EnemyPlane
{
public:
    Fish(qreal angle, qreal blood, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~Fish();
    void advance(int);
    void doCollide();
    void fall();
    void shoot();
};

#endif // FISH_H

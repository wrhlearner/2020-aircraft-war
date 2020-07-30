#ifndef FISH_H
#define FISH_H

#include "npc.h"
#include "randalg.h"

class NormalNPC : public Npc
{
public:
    NormalNPC(qreal blood, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~NormalNPC();
    void advance(int);
    void Collision();
    void BreakDown();
    void shoot();
    void hitAircraft();
};

#endif // FISH_H

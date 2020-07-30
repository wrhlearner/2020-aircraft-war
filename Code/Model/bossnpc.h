#ifndef BOSSNPC_H
#define BOSSNPC_H

#include "npc.h"

class BossNPC : public Npc
{
public:
    BossNPC(qreal blood, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~BossNPC(){}
    void advance(int);
    void Collision();
    void BreakDown();
    void shoot();
    void hitAircraft();
    int getName() const;
    void InvalidPosition();

private:
    int flag;
};

#endif // BOSSNPC_H

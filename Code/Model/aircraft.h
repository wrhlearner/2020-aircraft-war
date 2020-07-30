#ifndef FLIGHTVEHICLE_H
#define FLIGHTVEHICLE_H

#include "flyingobject.h"
#include "flyertypecast.h"
#include "generatebullet.h"

class Aircraft : public FlyingObject
{
    Q_OBJECT
public:
    Aircraft(qreal blood, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    virtual ~Aircraft() {}
    virtual void hitAircraft() = 0;
    virtual void shoot() = 0;
protected:
    qreal m_blood;
signals:
    void sig_score(int score);
    void sig_fall();
};

#endif // FLIGHTVEHICLE_H

#include "aircraft.h"

Aircraft::Aircraft(qreal blood, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent)
    :FlyingObject(w, h, speed, pixs, scene, parent), m_blood(blood) {}

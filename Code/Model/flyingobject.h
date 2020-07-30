#ifndef FLYER_H
#define FLYER_H

#include "global.h"

class FlyingObject : public QGraphicsObject
{
    Q_OBJECT
public:
    FlyingObject(qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    virtual ~FlyingObject() {}
    virtual int getName() const = 0;
    virtual void InvalidPosition() = 0;
    virtual void Collision() = 0;
    virtual void BreakDown() = 0;
    bool checkPos(CHECK_FLAG flag);
protected:
    qreal m_width, m_height, m_speed, m_pixmapIterator;
    //m_step用于控制飞机自动发射子弹，未采用
    uint m_shootCounter;
    //typedef QList<QPixmap> QPixmaps;
    QPixmaps m_pixmaps;
};

#endif // FLYER_H

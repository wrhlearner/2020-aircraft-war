#ifndef PLAYERPLANE_H
#define PLAYERPLANE_H

#include "aircraft.h"

class Player : public Aircraft
{
public:
    Player(qreal blood, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent = 0);
    ~Player(){}
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int getName() const;
    void advance(int);
    void InvalidPosition();
    void Collision();
    void BreakDown();
    void hitAircraft();
    void shoot();
    void emitBomb();
protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
private:
    qreal m_bomb;
    //每颗子弹的杀伤力
    int m_firePower;
    bool W, A, S, D, bomb;
};

#endif // PLAYERPLANE_H

#include "bomb.h"

Bomb::Bomb(qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent)
    :Bullet(w, h, speed, pixs, scene, parent) {}

Bomb::~Bomb() {}

QRectF Bomb::boundingRect() const {
    //return m_pixmaps.at(m_pixmapIterator).rect();
    return m_pixmaps.at(0).rect();
}

QPainterPath Bomb::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Bomb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    //painter->drawPixmap(0, 0, m_pixmaps.at(m_pixmapIterator));
    painter->drawPixmap(0, 0, m_pixmaps.at(0));
//    qDebug()<<tr("paint bomb.");
}

int Bomb::getName() const
{
    return BOMBNAME;
}

void Bomb::advance(int)
{
    if (!checkPos(UP) || !checkPos(DOWN) || !checkPos(LEFT) || !checkPos(RIGHT))
        InvalidPosition();
    else
    {
        QPointF pos = scenePos();
        pos.rx() -= xSpeed;
        pos.ry() -= ySpeed;
        setPos(pos);
//        qDebug()<<tr("bomb position: ")<<pos.x()<<tr(" ")<<pos.y();
    }
}

void Bomb::InvalidPosition()
{
    setVisible(false);
    deleteLater();
//    qDebug()<<tr("bomb on invalid position.");
}

void Bomb::Collision(){}

void Bomb::BreakDown()
{
    setVisible(false);
    deleteLater();
//    qDebug()<<tr("bomb break down.");
}

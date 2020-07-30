#include "npc.h"

Npc::Npc(qreal blood, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent):
    Aircraft(blood, w, h, speed, pixs, scene, parent), x_speed(0), y_speed(m_speed)
{}

Npc::~Npc() {}

QRectF Npc::boundingRect() const
{
    return m_pixmaps.at(0).rect();
}

QPainterPath Npc::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void Npc::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(0, 0, m_pixmaps.at(m_pixmapIterator));
}

int Npc::getName() const
{
    return ENEMYPLANENAME;
}

void Npc::InvalidPosition()
{
    setVisible(false);
    deleteLater();
}

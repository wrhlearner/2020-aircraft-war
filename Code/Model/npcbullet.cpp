#include "npcbullet.h"

NpcBullet::NpcBullet(qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent)
    :Bullet(w, h, speed, pixs, scene, parent){}

NpcBullet::~NpcBullet() {

}

QRectF NpcBullet::boundingRect() const
{
    return m_pixmaps.at(0).rect();
}

QPainterPath NpcBullet::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void NpcBullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(0, 0, m_pixmaps.at(0));
}

int NpcBullet::getName() const
{
    return ENEMYBULLETNAME;
}

void NpcBullet::advance(int)
{
    if (!checkPos(UP) || !checkPos(DOWN) || !checkPos(LEFT) || !checkPos(RIGHT))
    {
        InvalidPosition();
        return;
    }
    QPointF pos = scenePos();
    pos.rx() += xSpeed;
    pos.ry() += ySpeed;
    setPos(pos);
}

void NpcBullet::InvalidPosition() {
    setVisible(false);
    deleteLater();
}

void NpcBullet::Collision() {

}

void NpcBullet::BreakDown()
{
    setVisible(false);
    deleteLater();
}

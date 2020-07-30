#include "playerbullet.h"

PlayerBullet::PlayerBullet(qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent)
    :Bullet(w, h, speed, pixs, scene, parent){}

PlayerBullet::~PlayerBullet() {

}

QRectF PlayerBullet::boundingRect() const
{
    return m_pixmaps.at(0).rect();
}

QPainterPath PlayerBullet::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void PlayerBullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(0, 0, m_pixmaps.at(0));
//    qDebug()<<tr("paint bullet.");
}

int PlayerBullet::getName() const
{
    return PLAYERBULLETNAME;
}

void PlayerBullet::advance(int)
{
    if (!checkPos(UP) || !checkPos(DOWN) || !checkPos(LEFT) || !checkPos(RIGHT)) {
        InvalidPosition();
        return;
    }
    QPointF pos = scenePos();
    pos.rx() -= xSpeed;
    pos.ry() -= ySpeed;
    setPos(pos);
//    qDebug()<<tr("bullet position: ")<<pos.x()<<tr(" ")<<pos.y();
}

void PlayerBullet::InvalidPosition()
{
    setVisible(false);
    deleteLater();
//    qDebug()<<tr("player bullet on invalid position.");
}

void PlayerBullet::Collision() {}

void PlayerBullet::BreakDown()
{
    setVisible(false);
    deleteLater();
//    qDebug()<<tr("player bullet break down.");
}

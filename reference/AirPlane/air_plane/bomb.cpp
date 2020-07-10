#include "bomb.h"

Bomb::Bomb(qreal angel, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent)
    :Bullet(angel, w, h, speed, pixs, scene, parent) {

}

Bomb::~Bomb() {

}

QRectF Bomb::boundingRect() const {
    return m_pixs.at(m_pixpos).rect();
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
    painter->drawPixmap(0, 0, m_pixs.at(m_pixpos));
}

int Bomb::name() const
{
    return BOMBNAME;
}

void Bomb::advance(int)
{
    if (!checkPos(UP) || !checkPos(DOWN) || !checkPos(LEFT) || !checkPos(RIGHT)) {
        posLost();
        return;
    }
    m_step++;
    if (m_step == BOMBPIXSTEP) {
        m_step = 0;
        m_pixpos++;
        if (m_pixpos == 2) m_pixpos = 0;
    }
    QPointF pos = scenePos();
    pos.rx() -= xSpeed;
    pos.ry() -= ySpeed;
    setPos(pos);
    doCollide();
}

void Bomb::posLost() {
    setVisible(false);
    deleteLater();
}

void Bomb::doCollide()
{
    foreach (QGraphicsItem *t, collidingItems()) {
        if (t->type() != UnFlyer::TYPE) {
            Flyer *flyer = static_cast<Flyer*>(t);
            switch (flyer->name()) {
            case ENEMYBULLETNAME:
                flyer->fall();
                break;
            }
        }
    }
}

void Bomb::fall() {
    setVisible(false);
    deleteLater();
}

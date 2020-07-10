#include "fish.h"

Fish::Fish(qreal angle, qreal blood, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent):
    EnemyPlane(angle, blood, w, h, speed, pixs, scene, parent) {

}

Fish::~Fish() {

}

void Fish::advance(int)
{
    m_step++;
    if (m_step % FISHSHOOTSTEP == 0) {
        shoot();
    }
    if (m_step == FISHSHOOTSTEP * 10) m_step = 0;
    QPointF pos = scenePos();
    if (!checkPos(DOWN) || !checkPos(LEFT) || !checkPos(RIGHT)) {
        posLost();
        return;
    }
    if (!checkPos(UP)) {
        y_speed = -y_speed;
    }
    pos.ry() += y_speed;
    pos.rx() += x_speed;
    setPos(pos);
    doCollide();
}

void Fish::doCollide()
{
    foreach (QGraphicsItem *t, collidingItems()) {
        if (t->type() != UnFlyer::TYPE) {
            Flyer *flyer = static_cast<Flyer*>(t);
            if (flyer->name() == PLAYERBULLETNAME) {
                flyer->fall();
                strike();
                if (m_blood == 0) fall();
            }
            if (flyer->name() == BOMBNAME) {
                m_blood = 0;
                fall();
            }
        }
    }
}

void Fish::fall()
{
    setVisible(false);
    deleteLater();
    emit sig_score(FISHSCORE);
}

void Fish::shoot()
{
    int temp = Randomizer::creat(3);
    if (temp == 0) temp = 3;
    BulletFactory::EnemyBullets bullets = BulletFactory::ecreator(temp, scene());
    QPointF pos = scenePos();
    pos.rx() += m_w - FISHBULLETSIZE1;
    pos.ry() += m_h;
    foreach (EnemyBullet* bullet, bullets) {
        bullet->setPos(pos);
    }
}




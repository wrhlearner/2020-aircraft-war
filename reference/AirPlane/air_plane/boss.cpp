#include "boss.h"

Boss::Boss(qreal angle, qreal blood, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent):
    EnemyPlane(angle, blood, w, h, speed, pixs, scene, parent), flag(1) {

}

Boss::~Boss() {

}

void Boss::advance(int)
{
    m_step++;
    if (m_step % BOSSPIXSTEP == 0) {
        if (flag == 1 && m_pixpos == m_pixs.size() - 1) flag = -1;
        else if (flag == -1 && m_pixpos == 0) flag = 1;
        m_pixpos += flag;
        m_step = 0;
    }
    if (m_step % BOSSSHOOTSTEP == 0) {
        shoot();
    }
    if (m_step == BOSSSHOOTSTEP * 1000) m_step = 0;
    QPointF pos = scenePos();
    if (!checkPos(UP) || !checkPos(DOWN)) {
        y_speed = -y_speed;
    }
    if (!checkPos(LEFT) || !checkPos(RIGHT)) {
        x_speed = -x_speed;
    }
    pos.ry() += y_speed;
    pos.rx() += x_speed;
    setPos(pos);
    doCollide();
}

void Boss::doCollide()//Boss免疫大招
{
    foreach (QGraphicsItem *t, collidingItems()) {
        if (t->type() != UnFlyer::TYPE) {
            Flyer *flyer = static_cast<Flyer*>(t);
            if (flyer->name() == PLAYERBULLETNAME) {
                flyer->fall();
                strike();
                if (m_blood == 0) fall();
            }
        }
    }
}

void Boss::fall()
{
    setVisible(false);
    deleteLater();
    emit sig_score(BOSSSCORE);
}

void Boss::shoot()
{
    int temp;//这里temp的值应该在工厂中有宏定义，从而增强可读性，懒得写了
    if (1.0 * BOSSHP * 3 / 4 < m_blood && m_blood <= BOSSHP) temp = 4;
    else if (1.0 * BOSSHP * 2 / 4 < m_blood && m_blood <= 1.0 * BOSSHP * 3 / 4) temp = 5;
    else if (1.0 * BOSSHP * 1 / 4 < m_blood && m_blood <= 1.0 * BOSSHP * 2 / 4) temp = 6;
    else if (0 < m_blood && m_blood <= 1.0 * BOSSHP * 1 / 4) temp = 7;
    BulletFactory::EnemyBullets bullets = BulletFactory::ecreator(temp, scene());
    QPointF pos = scenePos();
    int bulletsize = BOSSBULLETSIZE1;
    if (temp == 5 || temp == 6 || temp == 7) bulletsize = BOSSSIZE / 2;
    pos.rx() += m_w / 2 - bulletsize / 2;
    pos.ry() += m_h / 2;
    foreach (EnemyBullet* bullet, bullets) {
        bullet->setPos(pos);
    }
}



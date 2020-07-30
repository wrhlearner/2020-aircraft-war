#include "bossnpc.h"

BossNPC::BossNPC(qreal blood, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent)
    :Npc(blood, w, h, speed, pixs, scene, parent), flag(1)
{
    m_pixmapIterator=0;
}
void BossNPC::advance(int)
{
    m_shootCounter++;
    if (m_shootCounter % BOSSSHOOTSTEP == 0) {
        shoot();
    }
    if (m_shootCounter == BOSSSHOOTSTEP * 1000)
        m_shootCounter = 0;
    QPointF pos = scenePos();
    if (!checkPos(UP) || !checkPos(DOWN))
    {
        //检测Boss在y轴方向是否超出游戏界面
        //若在一个方向超出游戏界面，命令Boss向相反方向运动，直至被玩家飞机击毁
        y_speed = -y_speed;
    }
    if (!checkPos(LEFT) || !checkPos(RIGHT))
    {
        //检测Boss在x轴方向是否超出游戏界面
        //若在一个方向超出游戏界面，命令Boss向相反方向运动，直至被玩家飞机击毁
        x_speed = -x_speed;
    }
    pos.ry() += y_speed;
    pos.rx() += x_speed;
    setPos(pos);
    Collision();
}

void BossNPC::Collision()
{
    foreach (QGraphicsItem *t, collidingItems())
    {
        if (t->type() != FlyerTypeCast::TYPE)
        {
            FlyingObject *flyer = static_cast<FlyingObject*>(t);
            if (flyer->getName() == PLAYERBULLETNAME)
            {
                flyer->BreakDown();
                if(m_blood == 0)
                    BreakDown();
                else
                    m_blood--;
            }
            else if(flyer->getName() == BOMBNAME)
            {
                flyer->BreakDown();
                if(m_blood>50)
                    m_blood-=50;
                else
                    BreakDown();
            }
        }
    }
}
void BossNPC::BreakDown()
{
    setVisible(false);
    deleteLater();
    emit sig_score(BOSSSCORE);
}

void BossNPC::shoot()
{
    //根据Hp值，发射不同类型的子弹
    int temp;
    if (1.0 * BOSSHP * 3 / 4 < m_blood && m_blood <= BOSSHP)
        temp = 4;
    else if (1.0 * BOSSHP * 2 / 4 < m_blood && m_blood <= 1.0 * BOSSHP * 3 / 4)
        temp = 5;
    else if (1.0 * BOSSHP * 1 / 4 < m_blood && m_blood <= 1.0 * BOSSHP * 2 / 4)
        temp = 6;
    else if (0 < m_blood && m_blood <= 1.0 * BOSSHP * 1 / 4)
        temp = 7;
    else
        temp=8;
    GenerateBullet::NpcBullets bullets = GenerateBullet::nbcreator(temp, scene());
    QPointF pos = scenePos();
    int bulletsize = BOSSBULLETSIZE1;
    if (temp == 5 || temp == 6 || temp == 7)
        bulletsize = BOSSSIZE / 2;
    pos.rx() += m_width / 2 - bulletsize / 2;
    pos.ry() += m_height / 2;
    foreach (NpcBullet* bullet, bullets)
    {
        bullet->setPos(pos);
    }
}
void BossNPC::hitAircraft()
{
    setVisible(false);
    deleteLater();
}
int BossNPC::getName() const
{
    return ENEMYPLANENAME;
}
void BossNPC::InvalidPosition()
{
    if(m_blood==0)
        BreakDown();
    else{
        if(!checkPos(UP)||!checkPos(DOWN))
            y_speed = -y_speed;
        if(!checkPos(LEFT)||!checkPos(RIGHT))
            x_speed = -x_speed;
    }
}

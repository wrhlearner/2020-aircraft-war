#include "normalnpc.h"

NormalNPC::NormalNPC(qreal blood, qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent):
    Npc(blood, w, h, speed, pixs, scene, parent) {

}

NormalNPC::~NormalNPC() {

}

void NormalNPC::advance(int)
{
    m_shootCounter++;
    if (m_shootCounter % FISHSHOOTSTEP == 0) {
        shoot();
    }
    if (m_shootCounter == FISHSHOOTSTEP * 10) m_shootCounter = 0;

    QPointF pos = scenePos();
    //检查NPC位置
    //NPC从屏幕下、左、右方超出游戏界面则消灭该NPC
    if (!checkPos(DOWN) || !checkPos(LEFT) || !checkPos(RIGHT)) {
        InvalidPosition();
        return;
    }
    //NPC从屏幕上方超出游戏界面则判定该NPC y轴速度方向出错
    if (!checkPos(UP)) {
        y_speed = -y_speed;
    }
    pos.ry() += y_speed;
    pos.rx() += x_speed;
    setPos(pos);
    //检测NPC与玩家飞机、玩家飞机子弹的碰撞
    Collision();
}

void NormalNPC::Collision()
{
    foreach (QGraphicsItem *t, collidingItems()) {
        if (t->type() != FlyerTypeCast::TYPE) {
            FlyingObject *flyer = static_cast<FlyingObject*>(t);
            if (flyer->getName() == PLAYERBULLETNAME)
            {
                flyer->BreakDown();
                if (m_blood == 0)
                    BreakDown();
                else
                    m_blood--;
            }
            else if(flyer->getName() == BOMBNAME)
            {
                flyer->BreakDown();
                BreakDown();
                qDebug()<<tr("hit by a bomb");
            }
        }
    }
}
void NormalNPC::hitAircraft()
{
    setVisible(false);
    deleteLater();
}
void NormalNPC::BreakDown()
{
    setVisible(false);
    deleteLater();
    emit sig_score(FISHSCORE);
}

void NormalNPC::shoot()
{
    //temp表示NPC子弹的杀伤力
    int temp = RandAlg::creat(3);
    if (temp == 0)
        temp = 3;
    GenerateBullet::NpcBullets bullets = GenerateBullet::nbcreator(temp, scene());
    QPointF pos = scenePos();
    pos.rx() += m_width/2 - FISHBULLETSIZE1/2;
    pos.ry() += m_height;
    foreach (NpcBullet* bullet, bullets) {
        bullet->setPos(pos);
    }
}




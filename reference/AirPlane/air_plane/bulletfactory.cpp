#include "bulletfactory.h"

BulletFactory::Bombs BulletFactory::bcreator(uint flag, QGraphicsScene *scene)
{
    Bombs temp;
    switch (flag) {
    case 0:
        break;
    case 1:
        QPixmaps t;
        t.append(QPixmap(bomb0));
        t.append(QPixmap(bomb1));
        temp.append(new Bomb(90, BOMBSIZE, BOMBSIZE, BOMBSPEED, t, scene));
        break;
    //可以继续添加，实现各种大招
    }
    return temp;
}

BulletFactory::PlayerBullets BulletFactory::pcreator(uint flag, QGraphicsScene *scene)
{
    PlayerBullets temp;
    if (flag == 0) {//作弊模式
        QPixmaps t;
        t.append(QPixmap(playerbullet0));
        for (int i = 0; i < 12; i++) {
            temp.append(new PlayerBullet(0 + 30 * i, PLAYERBULLETSIZE, PLAYERBULLETSIZE, PLAYERBULLETSPEED, t, scene));
        }
    }
    if (flag >= 1) {
        QPixmaps t;
        t.append(QPixmap(playerbullet0));
        temp.append(new PlayerBullet(90, PLAYERBULLETSIZE, PLAYERBULLETSIZE, PLAYERBULLETSPEED, t, scene));
    }
    if (flag >= 2) {
        QPixmaps t;
        t.append(QPixmap(playerbullet1));
        for (int i = 0; i < 2; i++) {
            temp.append(new PlayerBullet(80 + 20 * i, PLAYERBULLETSIZE, PLAYERBULLETSIZE, PLAYERBULLETSPEED, t, scene));
        }
    }
    if (flag >= 3) {
        QPixmaps t;
        t.append(QPixmap(playerbullet2));
        for (int i = 0; i < 2; i++) {
            temp.append(new PlayerBullet(40 + 20 * i, PLAYERBULLETSIZE, PLAYERBULLETSIZE, PLAYERBULLETSPEED, t, scene));
        }
        for (int i = 0; i < 2; i++) {
            temp.append(new PlayerBullet(120 + 20 * i, PLAYERBULLETSIZE, PLAYERBULLETSIZE, PLAYERBULLETSPEED, t, scene));
        }
    }
    //可以继续添加，让玩家变得更变态
    return temp;
}

BulletFactory::EnemyBullets BulletFactory::ecreator(uint flag, QGraphicsScene *scene)
{
    EnemyBullets temp;
    QPixmaps t, t1, t2;
    switch (flag) {
    case 0:
        break;
    case 1:
        t.append(QPixmap(fishbullet0));
        temp.append(new EnemyBullet(90, FISHBULLETSIZE1, FISHBULLETSIZE1, FISHBULLETSPEED1, t, scene));
        break;
    case 2:
        t.append(QPixmap(fishbullet1));
        for (int i = 0; i < 3; i++) {
            temp.append(new EnemyBullet(80 + 10 * i, FISHBULLETSIZE2, FISHBULLETSIZE2, FISHBULLETSPEED2, t, scene));
        }
        break;
    case 3:
        t.append(QPixmap(fishbullet2));
        for (int i = 0; i < 4; i++) {
            temp.append(new EnemyBullet(0 + 90 * i, FISHBULLETSIZE3, FISHBULLETSIZE3, FISHBULLETSPEED3, t, scene));
        }
        break;
    case 4:
        t.append(QPixmap(bossbullet0));
        for (int i = 0; i < 8; i++) {
            temp.append(new EnemyBullet(0 + 45 * i, BOSSBULLETSIZE1, BOSSBULLETSIZE1, BOSSBULLETSPEED1, t, scene));
        }
        break;
    case 5:
        t1.append(QPixmap(bossbullet0));
        for (int i = 0; i < 12; i++) {
            temp.append(new EnemyBullet(0 + 30 * i, BOSSBULLETSIZE1, BOSSBULLETSIZE1, BOSSBULLETSPEED1, t1, scene));
        }
        t2.append(QPixmap(bossbullet1));
        temp.append(new EnemyBullet(90, BOSSBULLETWIDTH2, BOSSBULLETHEIGHT2, BOSSBULLETSPEED2, t2, scene));
        break;
    case 6:
        t1.append(QPixmap(bossbullet0));
        for (int i = 0; i < 12; i++) {
            temp.append(new EnemyBullet(0 + 30 * i, BOSSBULLETSIZE1, BOSSBULLETSIZE1, BOSSBULLETSPEED1, t1, scene));
        }
        t2.append(QPixmap(bossbullet2));
        temp.append(new EnemyBullet(90, BOSSBULLETSIZE3, BOSSBULLETSIZE3, BOSSBULLETSPEED3, t2, scene));
        break;
    case 7:
        t1.append(QPixmap(bossbullet0));
        for (int i = 0; i < 36; i++) {
            temp.append(new EnemyBullet(0 + 10 * i, BOSSBULLETSIZE1, BOSSBULLETSIZE1, BOSSBULLETSPEED1, t1, scene));
        }
        t2.append(QPixmap(bossbullet2));
        temp.append(new EnemyBullet(90, BOSSBULLETSIZE3, BOSSBULLETSIZE3, BOSSBULLETSPEED3, t2, scene));
        break;
    //推荐继续添加子弹，尤其是可以根据时间变化的子弹（用m_step控制）
    }
    return temp;
}

#include "generatebullet.h"

GenerateBullet::PlayerBullets GenerateBullet::pcreator(int flag, QGraphicsScene *scene)
{
    PlayerBullets temp;
    QPixmaps t;
    t.append(QPixmap(playerbullet0));
    for (int i = 0; i < flag; i++) {
        temp.append(new PlayerBullet(PLAYERBULLETSIZE, PLAYERBULLETSIZE, PLAYERBULLETSPEED, t, scene));
    }
    return temp;
}

GenerateBullet::NpcBullets GenerateBullet::nbcreator(int flag, QGraphicsScene *scene)
{
    NpcBullets temp;
    QPixmaps t, t1, t2;
    switch (flag) {
    case 0:
        break;
    case 1:
        t.append(QPixmap(fishbullet0));
        temp.append(new NpcBullet(FISHBULLETSIZE1, FISHBULLETSIZE1, FISHBULLETSPEED1, t, scene));
        break;
    case 2:
        t.append(QPixmap(fishbullet1));
        for (int i = 0; i < 3; i++) {
            temp.append(new NpcBullet(FISHBULLETSIZE2, FISHBULLETSIZE2, FISHBULLETSPEED2, t, scene));
        }
        break;
    case 3:
        t.append(QPixmap(fishbullet2));
        for (int i = 0; i < 4; i++) {
            temp.append(new NpcBullet(FISHBULLETSIZE3, FISHBULLETSIZE3, FISHBULLETSPEED3, t, scene));
        }
        break;
    case 4:
        t.append(QPixmap(bossbullet0));
        for (int i = 0; i < 8; i++) {
            temp.append(new NpcBullet(BOSSBULLETSIZE1, BOSSBULLETSIZE1, BOSSBULLETSPEED1, t, scene));
        }
        break;
    case 5:
        t1.append(QPixmap(bossbullet0));
        for (int i = 0; i < 12; i++) {
            temp.append(new NpcBullet(BOSSBULLETSIZE1, BOSSBULLETSIZE1, BOSSBULLETSPEED1, t1, scene));
        }
        t2.append(QPixmap(bossbullet1));
        temp.append(new NpcBullet(BOSSBULLETWIDTH2, BOSSBULLETHEIGHT2, BOSSBULLETSPEED2, t2, scene));
        break;
    case 6:
        t1.append(QPixmap(bossbullet0));
        for (int i = 0; i < 12; i++) {
            temp.append(new NpcBullet(BOSSBULLETSIZE1, BOSSBULLETSIZE1, BOSSBULLETSPEED1, t1, scene));
        }
        t2.append(QPixmap(bossbullet2));
        temp.append(new NpcBullet(BOSSBULLETSIZE3, BOSSBULLETSIZE3, BOSSBULLETSPEED3, t2, scene));
        break;
    case 7:
        t1.append(QPixmap(bossbullet0));
        for (int i = 0; i < 36; i++) {
            temp.append(new NpcBullet(BOSSBULLETSIZE1, BOSSBULLETSIZE1, BOSSBULLETSPEED1, t1, scene));
        }
        t2.append(QPixmap(bossbullet2));
        temp.append(new NpcBullet(BOSSBULLETSIZE3, BOSSBULLETSIZE3, BOSSBULLETSPEED3, t2, scene));
        break;
    }
    return temp;
}

GenerateBullet::Bombs GenerateBullet::bcreator(int flag, QGraphicsScene *scene)
{
    Bombs temp;
    QPixmaps t;
    t.append(QPixmap(bomb0));
    t.append(QPixmap(bomb1));
    for (int i = 0; i < flag; i++) {
        temp.append(new Bomb(BOMBSIZE, BOMBSIZE, BOMBSPEED, t, scene));
    }
    return temp;
}

#include "planefactory.h"

PlaneFactory::BossPlanes PlaneFactory::bcreator(uint flag, QGraphicsScene *scene)
{
    BossPlanes temp;
    switch (flag) {
    case 1:
        QPixmaps t;
        t.append(QPixmap(boss0));
        t.append(QPixmap(boss1));
        t.append(QPixmap(boss2));
        t.append(QPixmap(boss3));
        int angle = Randomizer::creat(180);
        temp.append(new Boss(angle, BOSSHP, BOSSSIZE, BOSSSIZE, BOSSSPEED, t, scene));
    }
    return temp;
}

PlaneFactory::FishPlanes PlaneFactory::fcreator(uint flag, QGraphicsScene *scene)
{
    FishPlanes temp;
    for (uint i = 0; i < flag; i++) {
        QPixmaps t;
        int x = Randomizer::creat(3);
        if (x == 1) t.append(QPixmap(fish0));
        else if (x == 2) t.append(QPixmap(fish1));
        else if (x == 0) t.append(QPixmap(fish2));
        int angle = Randomizer::creat(180);
        temp.append(new Fish(angle, FISHHP, FISHSIZE, FISHSIZE, FISHSPEED, t, scene));
    }
    return temp;
}

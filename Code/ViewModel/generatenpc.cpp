#include "generatenpc.h"

GenerateNpc::NormalNpcs GenerateNpc::ncreator(uint flag, QGraphicsScene *scene)
{
    NormalNpcs temp;
    for (uint i = 0; i < flag; i++) {
        QPixmaps t;
        int x = RandAlg::creat(3);
        if (x == 1)
            t.append(QPixmap(fish0));
        else if (x == 2)
            t.append(QPixmap(fish1));
        else if (x == 0)
            t.append(QPixmap(fish2));
        temp.append(new NormalNPC(FISHHP, FISHSIZE, FISHSIZE, FISHSPEED, t, scene));
    }
    return temp;
}

GenerateNpc::BossNpcs GenerateNpc::bcreator(uint flag, QGraphicsScene *scene)
{
    BossNpcs temp;
    switch (flag) {
    case 1:
        QPixmaps t;
        t.append(QPixmap(boss0));
        temp.append(new BossNPC(BOSSHP, BOSSSIZE, BOSSSIZE, BOSSSPEED, t, scene));
    }
    return temp;
}

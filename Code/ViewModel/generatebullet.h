#ifndef BULLETFACTORY_H
#define BULLETFACTORY_H

#include "global.h"
#include "playerbullet.h"
#include "npcbullet.h"
#include "bomb.h"

class GenerateBullet
{
public:
    typedef QList<PlayerBullet*> PlayerBullets;
    typedef QList<NpcBullet*> NpcBullets;
    typedef QList<Bomb*> Bombs;
    static PlayerBullets pcreator(int flag, QGraphicsScene *scene);
    static NpcBullets nbcreator(int flag, QGraphicsScene *scene);
    static Bombs bcreator(int flag, QGraphicsScene *scene);
};

#endif // BULLETFACTORY_H

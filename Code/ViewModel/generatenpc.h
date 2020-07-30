#ifndef PLANEFACTORY_H
#define PLANEFACTORY_H

#include "global.h"
#include "normalnpc.h"
#include "bossnpc.h"
#include "randalg.h"

class GenerateNpc
{
public:
    typedef QList<NormalNPC*> NormalNpcs;
    typedef QList<BossNPC*> BossNpcs;
    static NormalNpcs ncreator(uint flag, QGraphicsScene *scene);
    static BossNpcs bcreator(uint flag, QGraphicsScene *scene);
};

#endif // PLANEFACTORY_H

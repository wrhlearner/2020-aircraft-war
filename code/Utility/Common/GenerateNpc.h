#ifndef GENERATENPC_H
#define GENERATENPC_H

#include "Global.h"
#include "BossNpc.h"
#include "NormalNpc.h"
#include "RandAlg.h"

class GenerateNpc
{
public:
	typedef std::list<BossNpc*> BossNpcPlanes;
	typedef std::list<NormalNpc*> NormalNpcPlanes;
	static BossNpcPlanes BossNpcCreator(int Number);
	static NormalNpcPlanes NormalNpcCreator(int Number);
};

#endif // !GENERATENPC_H

#pragma once
#include "BossNpc.h"
#include "NormalNpc.h"
#include "RandAlg.h"
#include<list>

class GenerateNpc
{
public:
	typedef std::list<BossNpc*> BossNpcPlanes;
	typedef std::list<NormalNpc*> NormalNpcPlanes;
	static BossNpcPlanes BossNpcCreator(int Number);
	static NormalNpcPlanes NormalNpcCreator(int Number);
};
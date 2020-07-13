#pragma once
#include "Bomb.h"
#include "Player.h"
#include "NormalNpc.h"
#include "BossNpc.h"
#include "PlayerBullet.h"
#include "NormalNpcBullet.h"
#include "BossNpcBullet.h"
#include "GenerateNpc.h"

class GenerateBullet
{
public:
	typedef std::list<Bomb*> Bombs;
	typedef std::list<PlayerBullet*> PlayerBullets;
	typedef std::list<NormalNpcBullet*> NormalNpcBullets;
	typedef std::list<BossNpcBullet*> BossNpcBullets;
	static Bombs bcreator(int Number);
	static PlayerBullets pcreator(int Number=PLAYERBULLETNUMBER);
	static NormalNpcBullets nncreator(GenerateNpc::NormalNpcPlanes NNTemp, const NormalNpc& TempNormalNpc, int Number=NORMALNPCBULLETNUMBER);
	static BossNpcBullets bncreator(GenerateNpc::BossNpcPlanes BNTemp, const BossNpc& TempBossNpc, int Number=BOSSNPCBULLETNUMBER);
};

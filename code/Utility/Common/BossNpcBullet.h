#pragma once
#include "NpcBullet.h"
#include "BossNpc.h"

class BossNpcBullet : public NpcBullet
{
public:
	BossNpcBullet();
	BossNpcBullet(char* PictureMap, int Name, double Width, double Height, double PosX, double PosY, double Speed, MOVEDIRECTION Direction, bool Exist, int ObjectType, bool Release, bool Display);
	BossNpcBullet(const BossNpcBullet& bn);
	~BossNpcBullet();
	void SetBossNpcBulletPosition(const BossNpc& bn);
};
#pragma once
#include "NpcBullet.h"
#include "NormalNpc.h"

class NormalNpcBullet : public NpcBullet
{
public:
	NormalNpcBullet();
	NormalNpcBullet(char* PictureMap, int Name, double Width, double Height, double PosX, double PosY, double Speed, MOVEDIRECTION Direction, bool Exist, int ObjectType, bool Release, bool Display);
	NormalNpcBullet(const NormalNpcBullet& nb);
	~NormalNpcBullet();
	void SetNormalNpcBulletPosition(const NormalNpc& nn);
};
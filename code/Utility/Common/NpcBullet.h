#pragma once
#include "Bullet.h"

class NpcBullet : public Bullet
{
public:
	NpcBullet();
	NpcBullet(char* PictureMap, int Name, double Width, double Height, double PosX, double PosY, double Speed, MOVEDIRECTION Direction, bool Exist, int ObjectType, bool Release, bool Display);
	NpcBullet(const NpcBullet& nb);
	~NpcBullet();
};
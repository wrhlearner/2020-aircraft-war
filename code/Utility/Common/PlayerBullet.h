#pragma once
#include "Bullet.h"

class PlayerBullet : public Bullet
{
public:
	PlayerBullet();
	PlayerBullet(char* PictureMap, int Name, double Width, double Height, double PosX, double PosY, double Speed, MOVEDIRECTION Direction, bool Exist, int ObjectType, bool Release, bool Display);
	PlayerBullet(const PlayerBullet& pb);
	~PlayerBullet() {}
};
#ifndef PLAYERBULLET_H
#define PLAYERBULLET_H

#include "Bullet.h"
#include "Player.h"

class PlayerBullet : public Bullet
{
public:
	PlayerBullet();
	PlayerBullet(char* PictureMap, int Name, double Width, double Height, double PosX, double PosY, double Speed, MOVEDIRECTION Direction, bool Exist, int ObjectType, bool Release, bool Display);
	PlayerBullet(const PlayerBullet& pb);
	~PlayerBullet() {}
	void SetBulletPosition(Player& p);
};

#endif // !PLAYERBULLET_H

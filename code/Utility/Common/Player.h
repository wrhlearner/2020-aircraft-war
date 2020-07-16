#ifndef PLAYER_H
#define PLAYER_H

#include "Aircraft.h"
#include "NormalNpc.h"
#include "BossNpc.h"
#include "NormalNpcBullet.h"
#include "BossNpcBullet.h"
#include "GenerateNpc.h"
#include "GenerateBullet.h"

class Player : public Aircraft
{
public:
	Player();
	Player(char* PictureMap, int Name, double Width, double Height, double StartPosX, double StartPosY, double Speed, MOVEDIRECTION Direction, bool Exist, int Blood, int FirePower);
	Player(const Player& p);
	~Player() {}
	int Collision(GenerateNpc::BossNpcPlanes bnp, GenerateNpc::NormalNpcPlanes nnp, GenerateBullet::BossNpcBullets bnb, GenerateBullet::NormalNpcBullets nnb);
	void Disappear();
	GenerateBullet::PlayerBullets LoadBullet(GenerateBullet::PlayerBullets pb);
};

#endif // !PLAYER_H

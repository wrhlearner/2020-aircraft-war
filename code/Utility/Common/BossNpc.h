#pragma once
#include "Npc.h"

class BossNpc : public Npc
{
public:
	BossNpc();
	BossNpc(char* PictureMap, int Name, double Width, double Height, double StartPosX, double StartPosY, double Speed, MOVEDIRECTION Direction, bool Exist, int Blood, int FirePower);
	BossNpc(const BossNpc& bn);
	~BossNpc();
	//virtual void Collision();
	//virtual void Disappear();
	//virtual void EmitBullet();
};
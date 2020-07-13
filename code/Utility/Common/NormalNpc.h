#pragma once
#include "Npc.h"
#include "Player.h"
#include "GenerateBullet.h"

class NormalNpc : public Npc
{
public:
	NormalNpc();
	NormalNpc(char* PictureMap, int Name, double Width, double Height, double StartPosX, double StartPosY, double Speed, MOVEDIRECTION Direction, bool Exist, int Blood, int FirePower, int Number);
	NormalNpc(const NormalNpc& nn);
	~NormalNpc();
	
	int Collision(Player& TempPlayer, GenerateBullet::PlayerBullets pb);
	GenerateBullet::NormalNpcBullets LoadBullet(GenerateBullet::NormalNpcBullets nnb);
};

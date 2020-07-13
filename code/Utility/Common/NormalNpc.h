#pragma once
#include "Npc.h"

class NormalNpc : public Npc
{
public:
	NormalNpc();
	NormalNpc(char* PictureMap, int Name, double Width, double Height, double StartPosX, double StartPosY, double Speed, MOVEDIRECTION Direction, bool Exist, int Blood, int FirePower, int Number);
	NormalNpc(const NormalNpc& nn);
	~NormalNpc();
	//virtual void Collision();
	//virtual void Disappear();
	//virtual void EmitBullet();
};

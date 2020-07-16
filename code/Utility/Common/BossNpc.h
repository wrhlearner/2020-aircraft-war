#ifndef BOSSNPC_H
#define BOSSNPC_H

#include "Npc.h"

class Player;
class GenerateBullet;

class BossNpc : public Npc
{
public:
	BossNpc();
	BossNpc(char* PictureMap, int Name, double Width, double Height, double StartPosX, double StartPosY, double Speed, MOVEDIRECTION Direction, bool Exist, int Blood, int FirePower, int Number);
	BossNpc(const BossNpc& bn);
	~BossNpc();
	//virtual void Collision();
	//virtual void Disappear();
	//virtual void EmitBullet();
	void SetNumber(int Number);
	int GetNumber() const;
};

#endif // !BOSSNPC_H

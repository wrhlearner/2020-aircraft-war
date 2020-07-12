#pragma once
#include "Aircraft.h"

class Player : public Aircraft
{
public:
	Player();
	Player(char* PictureMap, int Name, double Width, double Height, double StartPosX, double StartPosY, double Speed, MOVEDIRECTION Direction, bool Exist, int Blood, int FirePower);
	Player(const Player& p);
	~Player() {}
	//virtual void Collision();
	//virtual void Disappear();
	//virtual void EmitBullet();
	
};
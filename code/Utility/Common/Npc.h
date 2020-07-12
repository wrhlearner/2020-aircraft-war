#pragma once
#include "Aircraft.h"

class Npc : public Aircraft
{
public:
	Npc();
	Npc(char* PictureMap, int Name, double Width, double Height, double PosX, double PosY, double Speed, MOVEDIRECTION Direction, bool Exist, int Blood, int FirePower);
	Npc(const Npc& n);
	~Npc() {}
};
#pragma once
#include "Aircraft.h"

class Npc : public Aircraft
{
public:
	Npc();
	Npc(char* PictureMap, int Name, double Width, double Height, double PosX, double PosY, double Speed, MOVEDIRECTION Direction, bool Exist, int Blood, int FirePower, int Number);
	Npc(const Npc& n);
	~Npc() {}
	void SetNumber(int Number);
	int GetNumber();
protected:
	int m_Number;
	//Npc编号，用于唯一确定Npc
};

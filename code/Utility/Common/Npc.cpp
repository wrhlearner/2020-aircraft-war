#include "Npc.h"

Npc::Npc() {}
Npc::Npc(char* PictureMap, int Name, double Width, double Height, double PosX, double PosY, double Speed, MOVEDIRECTION Direction, bool Exist, int Blood, int FirePower, int Number):Aircraft(PictureMap, Name, Width, Height, PosX, PosY, Speed, Direction, Exist, Blood, FirePower) 
{
	m_Number = Number;
}
Npc::Npc(const Npc& n)
{
	m_Name = n.m_Name;
	m_Width = n.m_Width;
	m_Height = n.m_Height;
	m_PosX = n.m_PosX;
	m_PosY = n.m_PosY;
	m_Speed = n.m_Speed;
	m_Direction = n.m_Direction;
	m_Exist = n.m_Exist;
	m_PictureMap = n.m_PictureMap;
	m_Blood = n.m_Blood;
	m_FirePower = n.m_FirePower;
	m_Number = n.m_Number;
}
void Npc::SetNumber(int Number) { m_Number = Number; }
int Npc::GetNumber() { return m_Number; }

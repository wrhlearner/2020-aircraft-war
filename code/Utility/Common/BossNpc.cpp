#include "BossNpc.h"

BossNpc::BossNpc()
{
	m_Name = BOSSNPC;
	m_Width = BOSSNPCWIDTH;
	m_Height = BOSSNPCHEIGHT;
	m_PosX = -1.0;
	m_PosY = -1.0;
	m_Speed = BOSSNPCSPEED;
	m_Blood = BOSSNPCBLOOD;
	m_FirePower = BOSSNPCFIREPOWER;
	m_Direction = Neg;
	m_Exist = true;
}
BossNpc::BossNpc(char* PictureMap, int Name, double Width, double Height, double PosX, double PosY, double Speed, MOVEDIRECTION Direction, bool Exist, int Blood, int FirePower) :Npc(PictureMap, Name, Width, Height, PosX, PosY, Speed, Direction, Exist, Blood, FirePower) {}
BossNpc::BossNpc(const BossNpc& bn)
{
	m_Name = bn.m_Name;
	m_Width = bn.m_Width;
	m_Height = bn.m_Height;
	m_PosX = bn.m_PosX;
	m_PosY = bn.m_PosY;
	m_Speed = bn.m_Speed;
	m_Direction = bn.m_Direction;
	m_Exist = bn.m_Exist;
	m_PictureMap = bn.m_PictureMap;
	m_Blood = bn.m_Blood;
	m_FirePower = bn.m_FirePower;
}
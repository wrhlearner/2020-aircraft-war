#include "NormalNpc.h"

NormalNpc::NormalNpc() 
{
	m_Name = NORMALNPC;
	m_Width = NORMALNPCWIDTH;
	m_Height = NORMALNPCHEIGHT;
	m_PosX = -1.0;
	m_PosY = -1.0;
	m_Speed = NORMALNPCSPEED;
	m_Blood = NORMALNPCBLOOD;
	m_FirePower = NORMALNPCFIREPOWER;
	m_Direction = Neg;
	m_Exist = true;
}
NormalNpc::NormalNpc(char* PictureMap, int Name, double Width, double Height, double PosX, double PosY, double Speed, MOVEDIRECTION Direction, bool Exist, int Blood, int FirePower, int Number) :Npc(PictureMap, Name, Width, Height, PosX, PosY, Speed, Direction, Exist, Blood, FirePower, Number) {}
NormalNpc::NormalNpc(const NormalNpc& nn)
{
	m_Name = nn.m_Name;
	m_Width = nn.m_Width;
	m_Height = nn.m_Height;
	m_PosX = nn.m_PosX;
	m_PosY = nn.m_PosY;
	m_Speed = nn.m_Speed;
	m_Direction = nn.m_Direction;
	m_Exist = nn.m_Exist;
	m_PictureMap = nn.m_PictureMap;
	m_Blood = nn.m_Blood;
	m_FirePower = nn.m_FirePower;
	m_Number = nn.m_Number;
}

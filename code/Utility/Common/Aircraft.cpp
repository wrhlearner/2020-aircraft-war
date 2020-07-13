#include "Aircraft.h"

Aircraft::Aircraft(){}
Aircraft::Aircraft(char* PictureMap, int Name, double Width, double Height, double PosX, double PosY, double Speed, MOVEDIRECTION Direction, bool Exist, int Blood, int FirePower) :FlyingObject(PictureMap, Name, Width, Height, PosX, PosY, Speed, Direction)
{
	m_Blood = Blood;
	m_FirePower = FirePower;
}
Aircraft::Aircraft(const Aircraft& a)
{
	m_Name = a.m_Name;
	m_Width = a.m_Width;
	m_Height = a.m_Height;
	m_PosX = a.m_PosX;
	m_PosY = a.m_PosY;
	m_Speed = a.m_Speed;
	m_Direction = a.m_Direction;
	m_Exist = a.m_Exist;
	m_PictureMap = a.m_PictureMap;
	m_Blood = a.m_Blood;
	m_FirePower = a.m_FirePower;
}
void Aircraft::Disappear()
{
	m_Blood = 0;
	m_Exist = false;
}
void Aircraft::SetBlood(int Blood) { m_Blood = Blood; }
int Aircraft::GetBlood() const { return m_Blood; }
void Aircraft::SetFirePower(int FirePower) { m_FirePower = FirePower; }
int Aircraft::GetFirePower() const { return m_FirePower; }

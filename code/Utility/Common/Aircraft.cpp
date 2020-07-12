#include "Aircraft.h"
#include "pch.h"
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
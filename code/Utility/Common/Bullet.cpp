#include "Bullet.h"

Bullet::Bullet()
{
	m_PosX = -1.0;
	m_PosY = -1.0;
	m_Exist = false;

}
Bullet::Bullet(char* PictureMap, int Name, double Width, double Height, double PosX, double PosY, double Speed, MOVEDIRECTION Direction, bool Exist, int ObjectType, bool Release, bool Display) :FlyingObject(PictureMap, Name, Width, Height, PosX, PosY, Speed, Direction, Exist)
{
	m_ObjectType = ObjectType;
	m_Release = Release;
	m_Display = Display;
}
Bullet::Bullet(const Bullet& b)
{
	m_Name = b.m_Name;
	m_Width = b.m_Width;
	m_Height = b.m_Height;
	m_PosX = b.m_PosX;
	m_PosY = b.m_PosY;
	m_Speed = b.m_Speed;
	m_Direction = b.m_Direction;
	m_Exist = b.m_Exist;
	m_PictureMap = b.m_PictureMap;
	m_ObjectType = b.m_ObjectType;
	m_Release = b.m_Release;
	m_Display = b.m_Display;
}

int Bullet::GetObjectType() const{ return m_ObjectType; }
void Bullet::SetObjectType(int ObjectType) { m_ObjectType = ObjectType; }
bool Bullet::GetRelease() const{ return m_Release; }
void Bullet::SetRelease(bool Release) { m_Release = Release; }
bool Bullet::GetDisplay() const{ return m_Display; }
void Bullet::SetDisplay(bool Display) { m_Display = Display; }

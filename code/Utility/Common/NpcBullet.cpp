#include "NpcBullet.h"

NpcBullet::NpcBullet()
{
	m_Name = NPCBULLET;
	m_Width = NPCBULLETWIDTH;
	m_Height = NPCBULLETHEIGHT;
	m_Speed = BULLETSPEED;
	m_Direction = Neg;
	m_ObjectType = NORMALNPC;
	m_Release = false;
	m_Display = false;
}
NpcBullet::NpcBullet(char* PictureMap, int Name, double Width, double Height, double PosX, double PosY, double Speed, MOVEDIRECTION Direction, bool Exist, int ObjectType, bool Release, bool Display) :Bullet(PictureMap, Name, Width, Height, PosX, PosY, Speed, Direction, Exist, ObjectType, Release, Display) {}
NpcBullet::NpcBullet(const NpcBullet& nb)
{
	m_Name = nb.m_Name;
	m_Width = nb.m_Width;
	m_Height = nb.m_Height;
	m_PosX = nb.m_PosX;
	m_PosY = nb.m_PosY;
	m_Speed = nb.m_Speed;
	m_Direction = nb.m_Direction;
	m_Exist = nb.m_Exist;
	m_PictureMap = nb.m_PictureMap;
	m_ObjectType = nb.m_ObjectType;
	m_Release = nb.m_Release;
	m_Display = nb.m_Display;
}
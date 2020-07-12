#include "PlayerBullet.h"

PlayerBullet::PlayerBullet()
{
	m_Name = PLAYERBULLET;
	m_Width = PLAYERBULLETWIDTH;
	m_Height = PLAYERBULLETHEIGHT;
	m_Speed = BULLETSPEED;
	m_Direction = Pos;
	m_ObjectType = PLAYER;
	m_Release = false;
	m_Display = false;
}
PlayerBullet::PlayerBullet(char* PictureMap, int Name, double Width, double Height, double PosX, double PosY, double Speed, MOVEDIRECTION Direction, bool Exist, int ObjectType, bool Release, bool Display) :Bullet(PictureMap, Name, Width, Height, PosX, PosY, Speed, Direction, Exist, ObjectType, Release, Display) {}
PlayerBullet::PlayerBullet(const PlayerBullet& pb)
{
	m_Name = pb.m_Name;
	m_Width = pb.m_Width;
	m_Height = pb.m_Height;
	m_PosX = pb.m_PosX;
	m_PosY = pb.m_PosY;
	m_Speed = pb.m_Speed;
	m_Direction = pb.m_Direction;
	m_Exist = pb.m_Exist;
	m_PictureMap = pb.m_PictureMap;
	m_ObjectType = pb.m_ObjectType;
	m_Release = pb.m_Release;
	m_Display = pb.m_Display;
}
#include "pch.h"
#include "BossNpcBullet.h"

BossNpcBullet::BossNpcBullet() {}
BossNpcBullet::BossNpcBullet(char* PictureMap, int Name, double Width, double Height, double PosX, double PosY, double Speed, MOVEDIRECTION Direction, bool Exist, int ObjectType, bool Release, bool Display) :NpcBullet(PictureMap, Name, Width, Height, PosX, PosY, Speed, Direction, Exist, ObjectType, Release, Display) {}
BossNpcBullet::BossNpcBullet(const BossNpcBullet& bn)
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
	m_ObjectType = bn.m_ObjectType;
	m_Release = bn.m_Release;
	m_Display = bn.m_Display;
}
void BossNpcBullet::SetBossNpcBulletPosition(BossNpc& bn)
{
	m_PosX = bn.GetPositionX() + BOSSNPCBULLETWIDTHOFFSET;
	m_PosY = bn.GetPositionY() + BOSSNPCBULLETHEIGHTOFFSET;
}
void BossNpcBullet::SetBossNpcNumber(BossNpc& bn) { m_BossNpcNumber = bn.GetNumber(); }
void BossNpcBullet::SetBossNpcNumber(int BossNpcNumber) { m_BossNpcNumber = BossNpcNumber; }
int BossNpcBullet::GetBossNpcNumber() const { return m_BossNpcNumber; }

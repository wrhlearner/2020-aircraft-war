#include "pch.h"
#include "NormalNpcBullet.h"

NormalNpcBullet::NormalNpcBullet() {}
NormalNpcBullet::NormalNpcBullet(char* PictureMap, int Name, double Width, double Height, double PosX, double PosY, double Speed, MOVEDIRECTION Direction, bool Exist, int ObjectType, bool Release, bool Display) :NpcBullet(PictureMap, Name, Width, Height, PosX, PosY, Speed, Direction, Exist, ObjectType, Release, Display) {}
NormalNpcBullet::NormalNpcBullet(const NormalNpcBullet& nb)
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
void NormalNpcBullet::SetNormalNpcBulletPosition(NormalNpc& nn)
{
	m_PosX = nn.GetPositionX() + NORMALNPCBULLETWIDTHOFFSET;
	m_PosY = nn.GetPositionY() + NORMALNPCBULLETHEIGHTOFFSET;
}
void NormalNpcBullet::SetNormalNpcNumber(NormalNpc& nn) { m_NormalNpcNumber = nn.m_Number; }
void NormalNpcBullet::SetNormalNpcNumber(int NormalNpcNumber) { m_NormalNpcNumber = NormalNpcNumber; }
int NormalNpcBullet::GetNormalNpcNumber() const { return m_NormalNpcNumber; }

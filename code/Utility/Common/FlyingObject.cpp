#include "FlyingObject.h"

FlyingObject::FlyingObject()
{
	m_PosX = -1.0;
	m_PosY = -1.0;
	m_Exist = true;
}

FlyingObject::FlyingObject(char* PictureMap, int Name, double Width, double Height, double PosX, double PosY, double Speed, MOVEDIRECTION Direction, bool Exist)
{
	m_Name = Name;
	m_Width = Width;
	m_Height = Height;
	m_PosX = PosX;
	m_PosY = PosY;
	m_Speed = Speed;
	m_Direction = Direction;
	m_Exist = Exist;
	m_PictureMap.push_back(PictureMap);
}
FlyingObject::FlyingObject(const FlyingObject& fo)
{
	m_Name = fo.m_Name;
	m_Width = fo.m_Width;
	m_Height = fo.m_Height;
	m_PosX = fo.m_PosX;
	m_PosY = fo.m_PosY;
	m_Speed = fo.m_Speed;
	m_Direction = fo.m_Direction;
	m_Exist = fo.m_Exist;
	m_PictureMap = fo.m_PictureMap;
}

void FlyingObject::SetName(int Name) { m_Name = Name; }
int FlyingObject::GetName() { return m_Name; }
void FlyingObject::SetPictureMap(char* PictureMap, int Choice)
{
	switch (Choice) {
		case 0: 
			m_PictureMap.clear();
			break;
		case 1:
			m_PictureMap.push_back(PictureMap);
			break;
		case 2:
			m_PictureMap.pop_back();
			break;
	}
}
std::vector<char*> FlyingObject::GetPictureMap() { return m_PictureMap; }
void FlyingObject::SetSize(double Width, double Height) 
{ 
	m_Width = Width; 
	m_Height = Height; 
}
double FlyingObject::GetWidth() { return m_Width; }
double FlyingObject::GetHeight() { return m_Height; }
void FlyingObject::SetPosition(double x, double y)
{
	m_PosX = x;
	m_PosY = y;
}
double FlyingObject::GetPositionX() { return m_PosX; }
double FlyingObject::GetPositionY() { return m_PosY; }
void FlyingObject::SetSpeed(double Speed) { m_Speed = Speed; }
double FlyingObject::GetSpeed() { return m_Speed; }
void FlyingObject::SetDirection(MOVEDIRECTION Direction) { m_Direction = Direction; }
MOVEDIRECTION FlyingObject::GetDirection() { return m_Direction; }
void FlyingObject::SetExist(bool Exist) { m_Exist = Exist; }
bool FlyingObject::GetExist() { return m_Exist; }
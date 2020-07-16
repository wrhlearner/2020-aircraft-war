#include "pch.h"
#include "FlyingObject.h"

bool CheckCollision(double Width1, double Height1, double PosX1, double PosY1, double Width2, double Height2, double PosX2, double PosY2)
{
	//double Width1, double Height1, double PosX1, double PosY1 描述玩家飞机或玩家子弹参数；
	//double Width2, double Height2, double PosX2, double PosY2 描述Npc飞机或Npc子弹参数；
	//上下左右是从玩家角度判断的
	//加减参数值是从界面坐标系判断的
	double LeftBoundary1, RightBoundary1, UpBoundary1, DownBoundary1;
	double LeftBoundary2, RightBoundary2, UpBoundary2, DownBoundary2;
	
	LeftBoundary1 = PosX1;
	RightBoundary1 = PosX1 + Width1;
	UpBoundary1 = PosY1;
	DownBoundary1 = PosY1 + Height1;

	LeftBoundary2 = PosX2;
	RightBoundary2 = PosX2 + Width2;
	UpBoundary2 = PosY2;
	DownBoundary2 = PosY2 - Height2;

	if(((LeftBoundary1 > LeftBoundary2) && (LeftBoundary1 < RightBoundary2))|| (RightBoundary1 > LeftBoundary2) && (RightBoundary1 < RightBoundary2))
		if (((UpBoundary1 > DownBoundary2) && (UpBoundary1 < UpBoundary2))|| (DownBoundary1 > DownBoundary2) && (DownBoundary1 < UpBoundary2))
			return true;
	return false;
}

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

void FlyingObject::Disappear() 
{ 
	m_Exist = false; 
}

void FlyingObject::SetName(int Name) { m_Name = Name; }
int FlyingObject::GetName() const{ return m_Name; }
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
std::vector<char*> FlyingObject::GetPictureMap() const { return m_PictureMap; }
void FlyingObject::SetSize(double Width, double Height) 
{ 
	m_Width = Width; 
	m_Height = Height; 
}
double FlyingObject::GetWidth() const { return m_Width; }
double FlyingObject::GetHeight() const { return m_Height; }
void FlyingObject::SetPosition(double x, double y)
{
	m_PosX = x;
	m_PosY = y;
}
double FlyingObject::GetPositionX() const{ return m_PosX; }
double FlyingObject::GetPositionY() const{ return m_PosY; }
void FlyingObject::SetSpeed(double Speed) { m_Speed = Speed; }
double FlyingObject::GetSpeed() const{ return m_Speed; }
void FlyingObject::SetDirection(MOVEDIRECTION Direction) { m_Direction = Direction; }
MOVEDIRECTION FlyingObject::GetDirection() const{ return m_Direction; }
void FlyingObject::SetExist(bool Exist) { m_Exist = Exist; }
bool FlyingObject::GetExist() const{ return m_Exist; }

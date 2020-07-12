#pragma once
#include "Global.h"
#include <vector>

class FlyingObject
{
public:
	FlyingObject();
	FlyingObject(char* PictureMap, int Name, double Width, double Height, double PosX, double PosY, double Speed, MOVEDIRECTION Direction, bool Exist);
	FlyingObject(const FlyingObject& fo);
	virtual ~FlyingObject() {}
	
	//virtual void Collision() = 0;
	//virtual void Disappear() = 0;

	void SetName(int Name);
	int GetName();
	void SetPictureMap(char* PictureMap, int Choice);
	std::vector<char*> GetPictureMap();
	void SetSize(double Width, double Height);
	double GetWidth();
	double GetHeight();
	void SetPosition(double x, double y);
	double GetPositionX();
	double GetPositionY();
	void SetSpeed(double Speed);
	double GetSpeed();
	void SetDirection(MOVEDIRECTION Direction);
	MOVEDIRECTION GetDirection();
	void SetExist(bool Exist);
	bool GetExist();
	
protected:
	std::vector<char*> m_PictureMap;
	//物体图像，用于显示物体
	int m_Name;
	//物体名称，用于标识物体类型：玩家，Npc，子弹等
	double m_Width, m_Height;
	//物体大小，用于碰撞检测，物体的显示、消亡等
	double m_PosX, m_PosY;
	//物体位置(x,y)坐标
	double m_Speed;
	//物体移动速度
	MOVEDIRECTION m_Direction;
	//物体移动方向
	bool m_Exist;
	//物体是否存在。例如，飞机生命值是否大于0， 子弹是否击中目标
};
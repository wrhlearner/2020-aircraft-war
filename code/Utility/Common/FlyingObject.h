#ifndef FLYINGOBJECT_H
#define FLYINGOBJECT_H

#include "Global.h"

bool CheckCollision(double Width1, double Height1, double PosX1, double PosY1, double Width2, double Height2, double PosX2, double PosY2);

class FlyingObject
{
public:
	FlyingObject();
	FlyingObject(char* PictureMap, int Name, double Width, double Height, double PosX, double PosY, double Speed, MOVEDIRECTION Direction, bool Exist);
	FlyingObject(const FlyingObject& fo);
	virtual ~FlyingObject() {}

	//virtual void Collision() = 0;
	virtual void Disappear();

	void SetName(int Name);
	int GetName() const;
	void SetPictureMap(char* PictureMap, int Choice);
	std::vector<char*> GetPictureMap() const;
	void SetSize(double Width, double Height);
	double GetWidth() const;
	double GetHeight() const;
	void SetPosition(double x, double y);
	double GetPositionX() const;
	double GetPositionY() const;
	void SetSpeed(double Speed);
	double GetSpeed() const;
	void SetDirection(MOVEDIRECTION Direction);
	MOVEDIRECTION GetDirection() const;
	void SetExist(bool Exist);
	bool GetExist() const;

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

#endif // !FLYINGOBJECT_H

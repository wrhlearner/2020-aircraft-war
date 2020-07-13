#pragma once
#include "FlyingObject.h"

class Bullet :public FlyingObject
{
public:
	Bullet();
	Bullet(char* PictureMap, int Name, double Width, double Height, double PosX, double PosY, double Speed, MOVEDIRECTION Direction, bool Exist, int ObjectType, bool Release, bool Display);
	Bullet(const Bullet& b);
	virtual ~Bullet() {	}
	//virtual void Collision() = 0;
	//virtual void Disappear() = 0;

	int GetObjectType() const;
	void SetObjectType(int ObjectType);
	bool GetRelease() const;
	void SetRelease(bool Release);
	bool GetDisplay() const;
	void SetDisplay(bool Display);
protected:
	int m_ObjectType;
	//发射子弹的飞行器类型
	bool m_Release, m_Display;
	//是否已经发射子弹，子弹是否显示
};

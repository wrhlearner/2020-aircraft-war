#pragma once
#include "FlyingObject.h"

class Aircraft :public FlyingObject
{
public:
	Aircraft();
	Aircraft(char* PictureMap, int Name, double Width, double Height, double PosX, double PosY, double Speed, MOVEDIRECTION Direction, bool Exist, int Blood, int FirePower);
	Aircraft(const Aircraft& a);
	virtual ~Aircraft() {}
	/*virtual void EmitBullet() = 0;*/
	void Disappear();
	void SetBlood(int Blood);
	int GetBlood() const;
	void SetFirePower(int FirePower);
	int GetFirePower() const;
protected:
	int m_Blood;
	//飞行器生命值
	int m_FirePower;
	//飞行器子弹杀伤力
};

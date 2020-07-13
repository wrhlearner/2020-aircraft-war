#pragma once
#include "NpcBullet.h"
#include "NormalNpc.h"

class NormalNpcBullet : public NpcBullet
{
public:
	NormalNpcBullet();
	NormalNpcBullet(char* PictureMap, int Name, double Width, double Height, double PosX, double PosY, double Speed, MOVEDIRECTION Direction, bool Exist, int ObjectType, bool Release, bool Display);
	NormalNpcBullet(const NormalNpcBullet& nb);
	~NormalNpcBullet();
	void SetNormalNpcBulletPosition(const NormalNpc& nn);
	void SetNormalNpcNumber(const NormalNpc& nn);
	void SetNormalNpcNumber(int NormalNpcNumber);
	int GetNormalNpcNumber() const;
protected:
	int m_NormalNpcNumber;
	//将子弹与Npc绑定，便于在不同时间获得子弹的位置
};

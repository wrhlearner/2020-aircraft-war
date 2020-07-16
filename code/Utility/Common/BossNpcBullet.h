#ifndef BOSSNPCBULLET_H
#define BOSSNPCBULLET_H

#include "NpcBullet.h"
#include "BossNpc.h"

class BossNpcBullet : public NpcBullet
{
public:
	BossNpcBullet();
	BossNpcBullet(char* PictureMap, int Name, double Width, double Height, double PosX, double PosY, double Speed, MOVEDIRECTION Direction, bool Exist, int ObjectType, bool Release, bool Display);
	BossNpcBullet(const BossNpcBullet& bn);
	~BossNpcBullet();
	void SetBossNpcBulletPosition(BossNpc& bn);
	void SetBossNpcNumber(BossNpc& bn);
	void SetBossNpcNumber(int BossNpcNumber);
	int GetBossNpcNumber() const;
protected:
	int m_BossNpcNumber;
	//将子弹与Npc绑定，便于在不同时间获得子弹的位置
};

#endif // !BOSSNPCBULLET_H

#include "pch.h"
#include "Player.h"

Player::Player()
{
	m_Name = PLAYER;
	m_Width = PLAYERWIDTH;
	m_Height = PLAYERHEIGHT;
	m_PosX = -1.0;
	m_PosY = -1.0;
	m_Speed = PLAYERSPEED;
	m_Blood = PLAYERBLOOD;
	m_FirePower = PLAYERFIREPOWER;
	m_Direction = Pos;
	m_Exist = true;
}
Player::Player(char* PictureMap, int Name, double Width, double Height, double PosX, double PosY, double Speed, MOVEDIRECTION Direction, bool Exist, int Blood, int FirePower) :Aircraft(PictureMap, Name, Width, Height, PosX, PosY, Speed, Direction, Exist, Blood, FirePower){}
Player::Player(const Player& p)
{
	m_Name = p.m_Name;
	m_Width = p.m_Width;
	m_Height = p.m_Height;
	m_PosX = p.m_PosX;
	m_PosY = p.m_PosY;
	m_Speed = p.m_Speed;
	m_Direction = p.m_Direction;
	m_Exist = p.m_Exist;
	m_PictureMap = p.m_PictureMap;
	m_Blood = p.m_Blood;
	m_FirePower = p.m_FirePower;
}
void Player::Disappear() { m_Exist = false; }
int Player::Collision(GenerateNpc::BossNpcPlanes bnp, GenerateNpc::NormalNpcPlanes nnp, GenerateBullet::BossNpcBullets bnb, GenerateBullet::NormalNpcBullets nnb)
{
	//碰撞处理过程：
	//    检查Npc及子弹是否有效存在
	//    检查空间上是否有重叠，判断碰撞是否发生
	//    改变玩家飞机、Npc及子弹的属性
	if (!nnp.empty()) 
	{
		std::list<NormalNpc*>::iterator nnpIterator = nnp.begin();
		while (nnpIterator != nnp.end())
		{
			if ((*nnpIterator)->GetExist())
			{
				if (CheckCollision(m_Width, m_Height, m_PosX, m_PosY, (*nnpIterator)->GetWidth(), (*nnpIterator)->GetHeight(), (*nnpIterator)->GetPositionX(), (*nnpIterator)->GetPositionY()))
				{
					Disappear();
					(*nnpIterator)->Disappear();
					return 0;
				}
			}
		}
	}
	if (!nnb.empty()) 
	{
		std::list<NormalNpcBullet*>::iterator nnbIterator = nnb.begin();
		while (nnbIterator != nnb.end())
		{
			if ((*nnbIterator)->GetExist())
			{
				if (CheckCollision(m_Width, m_Height, m_PosX, m_PosY, (*nnbIterator)->GetWidth(), (*nnbIterator)->GetHeight(), (*nnbIterator)->GetPositionX(), (*nnbIterator)->GetPositionY()))
				{
					if (m_Blood > NORMALNPCFIREPOWER)
					{
						m_Blood = m_Blood - NORMALNPCFIREPOWER;
						(*nnbIterator)->Disappear();
					}
					else
					{
						Disappear();
						(*nnbIterator)->Disappear();
						return 0;
					}
				}
			}
		}
	}
}
GenerateBullet::PlayerBullets Player::LoadBullet(GenerateBullet::PlayerBullets pb)
{
	if (pb.size() == 0) 
	{
		GenerateBullet::PlayerBullets TempPB = GenerateBullet::pcreator(PLAYERBULLETNUMBER);
		return TempPB;

	}
	else if (pb.size() < PLAYERBULLETNUMBER) 
	{	
		for (int i = 0; i < PLAYERBULLETNUMBER-pb.size(); i++)
			pb.push_back(new PlayerBullet());
		std::list<PlayerBullet*>::iterator pbIterator = pb.begin();
		while (pbIterator != pb.end()) {
			(*pbIterator)->SetExist(true);
			pbIterator++;
		}
		return pb;
	}
}

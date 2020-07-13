#include "NormalNpc.h"

NormalNpc::NormalNpc() 
{
	m_Name = NORMALNPC;
	m_Width = NORMALNPCWIDTH;
	m_Height = NORMALNPCHEIGHT;
	m_PosX = -1.0;
	m_PosY = -1.0;
	m_Speed = NORMALNPCSPEED;
	m_Blood = NORMALNPCBLOOD;
	m_FirePower = NORMALNPCFIREPOWER;
	m_Direction = Neg;
	m_Exist = true;
}
NormalNpc::NormalNpc(char* PictureMap, int Name, double Width, double Height, double PosX, double PosY, double Speed, MOVEDIRECTION Direction, bool Exist, int Blood, int FirePower, int Number) :Npc(PictureMap, Name, Width, Height, PosX, PosY, Speed, Direction, Exist, Blood, FirePower, Number) {}
NormalNpc::NormalNpc(const NormalNpc& nn)
{
	m_Name = nn.m_Name;
	m_Width = nn.m_Width;
	m_Height = nn.m_Height;
	m_PosX = nn.m_PosX;
	m_PosY = nn.m_PosY;
	m_Speed = nn.m_Speed;
	m_Direction = nn.m_Direction;
	m_Exist = nn.m_Exist;
	m_PictureMap = nn.m_PictureMap;
	m_Blood = nn.m_Blood;
	m_FirePower = nn.m_FirePower;
	m_Number = nn.m_Number;
}
int NormalNpc::Collision(Player& TempPlayer, GenerateBullet::PlayerBullets pb)
{
	//碰撞处理过程：
	//    检查Npc及子弹是否有效存在
	//    检查空间上是否有重叠，判断碰撞是否发生
	//    改变玩家飞机、Npc及子弹的属性
	if (TempPlayer.GetExist()) 
	{
		if (CheckCollision(TempPlayer.GetWidth(), TempPlayer.GetHeight(), TempPlayer.GetPositionX(), TempPlayer.GetPositionY(), m_Width, m_Height, m_PosX, m_PosY))
		{
			Disappear();
			TempPlayer.Disappear();
			return 0;
		}
	}
	if (!pb.empty())
	{
		std::list<PlayerBullet*>::iterator pbIterator = pb.begin();
		while (pbIterator != pb.end())
		{
			if ((*pbIterator)->GetExist())
			{
				if (CheckCollision((*pbIterator)->GetWidth(), (*pbIterator)->GetHeight(), (*pbIterator)->GetPositionX(), (*pbIterator)->GetPositionY(), m_Width, m_Height, m_PosX, m_PosY))
				{
					if (m_Blood > PLAYERFIREPOWER)
						m_Blood = m_Blood - PLAYERFIREPOWER;
					else
					{
						Disappear();
						(*pbIterator)->Disappear();
						return 0;
					}
				}
			}
		}
	}
}
GenerateBullet::NormalNpcBullets LoadBullet(GenerateBullet::NormalNpcBullets nnb) 
{
	if (nnb.size() == 0)
	{
		GenerateBullet::NormalNpcBullets NNBTemp;
		for (int i = 0; i < NORMALNPCBULLETNUMBER; i++)
			NNBTemp.push_back(new NormalNpcBullet());
		std::list<NormalNpcBullet*>::iterator pnnb = NNBTemp.begin();
		while (pnnb != NNBTemp.end())
		{
			(*pnnb)->SetNormalNpcNumber(m_Number);
			(*pnnb)->SetExist(true);
			pnnb++;
		}
		return NNBTemp;
	}
	else
		return nnb;
}

#include "GenerateBullet.h"

GenerateBullet::Bombs GenerateBullet::bcreator(int Number)
{
	
}
GenerateBullet::PlayerBullets GenerateBullet::pcreator(int Number=PLAYERBULLETNUMBER)
{
	PlayerBullets Temp;
	for (int i = 0; i < Number; i++)
		Temp.push_back(new PlayerBullet());
	std::list<PlayerBullet*>::iterator pb = Temp.begin();
	while (pb != Temp.end()) {
		(*pb)->SetExist(true);
		pb++;
	}
}
GenerateBullet::NormalNpcBullets GenerateBullet::nncreator(GenerateNpc::NormalNpcPlanes NNTemp, const NormalNpc& TempNormalNpc, int Number = NORMALNPCBULLETNUMBER)
{
	std::list<NormalNpc*>::iterator NNTempP = NNTemp.begin();
	while (NNTempP != NNTemp.end()) 
	{
		NormalNpcBullets NNBTemp;
		int NormalNpcNumber;
		NormalNpcNumber = (*NNTempP)->GetNumber();
		for (int i = 0; i < Number; i++)
			NNBTemp.push_back(new NormalNpcBullet());
		std::list<NormalNpcBullet*>::iterator pnnb = NNBTemp.begin();
		while (pnnb != NNBTemp.end()) 
		{
			/*pnnb->SetNormalNpcBulletPosition(*NNTempP);*/
			(*pnnb)->SetNormalNpcNumber(NormalNpcNumber);
			(*pnnb)->SetExist(true);
			pnnb++;
		}
	}
}
GenerateBullet::BossNpcBullets GenerateBullet::bncreator(int Number, GenerateNpc::BossNpcPlanes BNTemp, const BossNpc& TempBossNpc, int Number = BOSSNPCBULLETNUMBER)
{
	std::list<BossNpc*>::iterator BNTempP = BNTemp.begin();
	while (BNTempP != BNTemp.end())
	{
		BossNpcBullets BNBTemp;
		int BossNpcNumber;
		BossNpcNumber = (*BNTempP)->GetNumber();
		for (int i = 0; i < Number; i++)
			BNBTemp.push_back(new BossNpcBullet());
		std::list<BossNpcBullet*>::iterator pbnb = BNBTemp.begin();
		while (pbnb != BNBTemp.end())
		{
			/*pbnb->SetBossNpcBulletPosition(*BNTempP);*/
			(*pbnb)->SetBossNpcNumber(BossNpcNumber);
			(*pbnb)->SetExist(true);
			pbnb++;
		}
	}
}

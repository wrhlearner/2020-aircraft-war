#include "GenerateNpc.h"

GenerateNpc::BossNpcPlanes GenerateNpc::BossNpcCreator(int Number)
{
	BossNpcPlanes Temp;
	for (int i = 0; i < Number; i++)
		Temp.push_back(new BossNpc());
	std::list<BossNpc*>::iterator p = Temp.begin();
	int i = 0;
	while (p != Temp.end()) {
		p->SetNumber(i);
		p->SetPosition(GetRandNum(SCENEWIDTH + BOSSNPCWIDTH, 0, i), 0);
		i++;
		p++;
	}
}
GenerateNpc::NormalNpcPlanes GenerateNpc::NormalNpcCreator(int Number)
{
	NormalNpcPlanes Temp;
	for (int i = 0; i < Number; i++)
		Temp.push_back(new NormalNpc());
	std::list<NormalNpc*>::iterator p = Temp.begin();
	int i = 0;
	while (p != Temp.end()) {
		p->SetNumber(i);
		p->SetPosition(GetRandNum(SCENEWIDTH+NORMALNPCWIDTH, 0, i), 0);
		i++;
		p++;
	}
}
#include "pch.h"
#include "RandAlg.h"

int GetRandNum(int UpperBound, int LowerBound, int Seed)
{
	srand(Seed);
	int Number;
	int Result;
	Number = UpperBound - LowerBound + 1;
	Result = rand() % Number + LowerBound;
	return Result;
}

#include "randalg.h"

RandAlg::RandAlg(QObject *parent) : QObject(parent) {}

int RandAlg::creat(int x)
{
    //产生[0,x)上的随机数
    return qrand() % x;
}

int RandAlg::creat(int x, int y)
{
    //产生[0,y)上的随机数
    return qrand() % (y - x) + x;
}

#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include "global.h"

class RandAlg : public QObject
{
    Q_OBJECT
public:
    static int creat(int x);
    static int creat(int x, int y);
private:
    explicit RandAlg(QObject *parent = 0);
};

#endif // RANDOMIZER_H

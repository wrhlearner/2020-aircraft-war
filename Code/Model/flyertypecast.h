#ifndef UNFLYER_H
#define UNFLYER_H

#include "global.h"

class FlyerTypeCast : public QGraphicsObject
{
    Q_OBJECT
public:
    FlyerTypeCast(QGraphicsItem *parent = 0);
    ~FlyerTypeCast();
    enum {TYPE = UserType + 1};
    int type() const;
};

#endif // UNFLYER_H

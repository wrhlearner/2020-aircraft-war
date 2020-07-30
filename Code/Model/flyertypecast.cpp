#include "flyertypecast.h"

FlyerTypeCast::FlyerTypeCast(QGraphicsItem *parent) : QGraphicsObject(parent) {}

FlyerTypeCast::~FlyerTypeCast() {}

int FlyerTypeCast::type() const {
    return UserType + 1;
}

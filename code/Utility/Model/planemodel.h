#ifndef PLANEMODEL_H
#define PLANEMODEL_H
#include "map.h"
#include "bulletmodel.h"

class planemodel:public Proxy_PropertyNotification<planemodel>
{
public:
    planemodel();
    void shoot();
    void setPosition(int x,int y );
public:
	QPixmap m_Plane;
	int m_X;
	int m_Y;
	int m_recorder;
	QRect m_Rect;
    Bullet m_bullets[BULLET_NUM];
};

#endif // PLANEMODEL_H

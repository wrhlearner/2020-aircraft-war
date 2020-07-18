#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H

#include <QPixmap>

class enemyPlane
{
public:
    enemyPlane();
    void updatePosition();
public:
    QPixmap m_enemy;
    //位置
    int m_X;
    int m_Y;
    QRect m_Rect;

    bool m_Free;
    int m_Speed;

};

#endif // ENEMYPLANE_H

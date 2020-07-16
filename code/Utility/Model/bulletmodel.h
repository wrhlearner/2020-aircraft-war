#ifndef BULLETMODEL_H
#define BULLETMODEL_H


class bulletmodel:public Proxy_PropertyNotification<bulletmodel>
{

public:
    bulletmodel();
    void updatePosition();
public:
    QPixmap m_Bullet;
    int m_X;
    int m_Y;
    int m_Speed;
    bool m_Free;
    QRect m_Rect;
};

#endif // BULLETMODEL_H

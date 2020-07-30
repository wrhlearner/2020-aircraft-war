#include "flyingobject.h"

FlyingObject::FlyingObject(qreal w, qreal h, qreal speed, const QPixmaps &pixs, QGraphicsScene *scene, QGraphicsItem *parent)
    : QGraphicsObject(parent), m_width(w), m_height(h), m_speed(speed), m_pixmapIterator(0), m_shootCounter(0)
{
    for (int i = 0; i < pixs.size(); i++) {
        QPixmap temp(pixs.at(i));
        QPixmap t;
        //保持图像长宽比例放大
        //至放缩后长宽中较小值等于规定长宽值
        t = temp.scaled(m_width, m_height, Qt::KeepAspectRatioByExpanding);
        m_pixmaps.append(t);
    }
    scene->addItem(this);
}

bool FlyingObject::checkPos(CHECK_FLAG flag)
{
    //检测Flyer对象在游戏界面位置的合理性
    //处于合理位置返回true
    //处于不合理位置返回false
    bool ok = false;
    switch (flag) {
    case UP:
        //QPointF QGraphicsItem::scenePos() const
        //返回Flyer对象在场景坐标系中的位置坐标
        //qreal &QPointF::ry()
        //返回对该点y坐标的引用，可以对y坐标进行修改
        //判断Flyer在y方向可以到达的最小位置（屏幕最上）是否满足要求
        if (scenePos().ry() >= -m_height)
            ok = true;
        break;
    case DOWN:
        //判断Flyer在y方向可以到达的最大位置（屏幕最下）是否满足要求
        if (scenePos().ry() <= SCENEHEIGHT)
            ok = true;
        break;
    case LEFT:
        //判断Flyer在x方向可以到达的最小位置（屏幕最左）是否满足要求
        if (scenePos().rx() >= 0)
            ok = true;
        break;
    case RIGHT:
        //判断Flyer在x方向可以到达的最大位置（屏幕最右）是否满足要求
        if (scenePos().rx() <= SCENEWIDTH-m_width)
            ok = true;
        break;
    }
    return ok;
}

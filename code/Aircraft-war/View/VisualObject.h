#ifndef __VISUALOBJECT_H__
#define __VISUALOBJECT_H__

#include <QGraphicsPixmapItem>


class VisualObject : public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    void get_VOpointer();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0);
    void get_Pixmap();

public:
    void BEGIN_MSG_MAP(VisualObject);
    void END_MSG_MAP();

private:
    //Pixmap VO_Pixmap;
    char* PictureMap;
};

#endif
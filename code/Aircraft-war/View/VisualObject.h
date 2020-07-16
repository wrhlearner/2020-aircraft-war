#ifndef __VISUALOBJECT_H__
#define __VISUALOBJECT_H__

#include <QGraphicsPixmapItem>
#include <QPaintEvent>  

QT_BEGIN_NAMESPACE
namespace Ui { class GraphicsPixmapItem; }
QT_END_NAMESPACE

class VisualObject : public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    VisualObject(QGraphicsItem *parent = nullptr);     // Create a Pixmap
    
    ~VisualObject(); 

public:
    void BEGIN_MSG_MAP(VisualObject);
    void END_MSG_MAP();
};

#endif
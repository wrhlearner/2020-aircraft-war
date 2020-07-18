#include <VisualObject.h>
#include <QGraphicsPixmapItem>
#include <QPaintEvent>

std::shared_ptr<VisualObject> VisualObject::get_VOpointer()
{
	return std::static_pointer_cast<VisualObject>(this)
}

void VisualObject::paint(MainWindow *MWd, QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0)
{
    QPixmap pixmap = this->pixmap();  
    QRect rect = pixmap.rect();  
    painter->drawPixmap(this, this->VO_PixMap);  
}

void VisualObject::get_Pixmap(){
    Pixmap VO_Pixmap；
    VO_Pixmap.load(QString(this->PictureMap));
    setpixmap(VO_Pixmap);
}
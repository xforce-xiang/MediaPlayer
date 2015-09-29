#include "videowidget.h"
#include <QKeyEvent>
#include <QMouseEvent>


VideoWidget::VideoWidget(QWidget *parent) : QVideoWidget(parent)
{

}



void VideoWidget::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Escape && isFullScreen())
    {
        setFullScreen(false);
        event->accept();
    }
    else if(event->key() == Qt::Key_Enter && event->modifiers() & Qt::Key_Alt)//修饰键是Alt
    {
        setFullScreen(!isFullScreen());
        event->accept();
    }
    else
    {
        QVideoWidget::keyPressEvent(event);
    }
}

void VideoWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    setFullScreen(!isFullScreen());
    event->accept();
}

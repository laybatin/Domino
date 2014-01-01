#include "mylabel.h"
#include <QMouseEvent>
#include <QDebug>
MyLabel::MyLabel(QWidget *parent) :
    QLabel(parent)
{
    setAcceptDrops(true);
    isPress = false;
}

MyLabel::MyLabel(const QString &src)
{
    this->setText(src);
    setAcceptDrops(true);
    isPress = false;

}

void MyLabel::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "WTF press!";
    isPress = true;
    event->accept();
    if(isWindow())
        offset = event->globalPos() - pos();
    else
        offset = event->pos();

}

void MyLabel::mouseMoveEvent(QMouseEvent *event)
{
    if(isPress)
    {
        qDebug() << "why!!!";
        event->accept();
        if(isWindow())
            move(event->globalPos() - offset);
        else
            move(mapToParent(event->pos()) - offset);
    }

}

void MyLabel::mouseReleaseEvent(QMouseEvent *event)
{
    isPress = false;
    event->accept();
    offset = QPoint();

}

void MyLabel::mouseDoubleClickEvent(QMouseEvent *event)
{
    event->accept();
    emit doubleClicked();
}

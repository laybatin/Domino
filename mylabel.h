#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QPoint>
class MyLabel : public QLabel
{
    Q_OBJECT
public:
    MyLabel(QWidget *parent = 0);
    MyLabel(const QString & src);
    QPoint offset;

signals:
    void doubleClicked();

public slots:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseDoubleClickEvent(QMouseEvent* event);

private:
    bool isPress;

};

#endif // MYLABEL_H

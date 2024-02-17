#include "board_widget.hh"
#include <QDebug>
BoardWidget::BoardWidget(QWidget *parent)
    : QWidget{parent}
{

    _boardTimer = new QTimer();
    _p = new QPoint();
    _boardTimer->setInterval(300);

    connect(_boardTimer, SIGNAL(timeout()), this, SLOT(timerEventHandler()));
    update();
    _boardTimer->start();

}

void BoardWidget::paintEvent(QPaintEvent *)
{
    QPainter p2(this);
//    qInfo()<<height()<<"    "<<width();
    const double _ScaleY=height()/static_cast<double>(tlo->height());
    const double _ScaleX=width()/static_cast<double>(tlo->width());
    p2.scale(_ScaleX,_ScaleY);
    p2.drawRect(0,0,width()+1, height()+1);
    p2.drawImage(0,0, *tlo);
    update();
}

void BoardWidget::timerEventHandler()
{
    *_p = this->mapFromGlobal(QCursor::pos());
    qDebug()<<*_p<<" on screen: "<<height()<<"    "<<width();
}


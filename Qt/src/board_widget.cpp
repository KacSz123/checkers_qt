#include "board_widget.hh"
#include <QDebug>
#include<iostream>
BoardWidget::BoardWidget(QWidget *parent)
    : QWidget{parent}
{



    piece =  std::unique_ptr<QImage>(new QImage(":/board_img/piece_png"));
    /*
     * , tmpSquare2
            tmpSquare2._position = 4*(i+1) + j;
            tmpSquare2._qPoint.setX(int((tlo->width()*boardRatioX)+(j*2)*tlo->width()*squareRatioX));
            tmpSquare2._qPoint.setY(int(tlo->height()*boardRatioY+(i*2)*tlo->width()*squareRatioY));
            _squaresCoordsList.push_back(tmpSquare2);
     * */
    SquarePoint tmpSquare;
    int tmp;

    for(int i=0; i<=7; ++i)
    {

        for(int j=1; j<=4; ++j)
        {
            i%2==0 ?  tmp = (2*j)-1 : tmp = (2*(j-1));
            tmpSquare._position = 4*i + j;
            tmpSquare._qPoint.setX(int((tlo->width()*boardRatioX)+tmp*tlo->width()*squareRatioX));
            tmpSquare._qPoint.setY(int((tlo->height()*boardRatioY)+i*tlo->height()*squareRatioY));



            _squaresCoordsList.push_back(tmpSquare);
        }
    }
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
//    piece->
//    p2.scale(_ScaleX/1.7,_ScaleY/1.7)

    QImage draw = piece->scaled(int(tlo->width()*squareRatioX),int(tlo->height()*squareRatioY));
//    qInfo()<<"squareX"<<int(width()*0.1)<<"squareY"<<int(height()*0.1);
    p2.drawImage(int((tlo->width()*boardRatioX)+4*tlo->width()*squareRatioX),int(tlo->height()*boardRatioY+3*tlo->width()*squareRatioY), draw);
    update();
}

void BoardWidget::timerEventHandler()
{




    *_p = this->mapFromGlobal(QCursor::pos());
    qDebug()<<*_p<<" on screen: "<<height()<<"    "<<width();
    list<SquarePoint>::iterator it;
    int tp;
    QPoint  p2;

        for (it =  _squaresCoordsList.begin(); it != _squaresCoordsList.end(); ++it)
        {
            p2 = (*it)._qPoint;
            if(_p->rx() > p2.rx() - int(tlo->width()*squareRatioX)/2 && _p->rx() < p2.rx() + int(tlo->width()*squareRatioX)/2 &&
               _p->ry() > p2.ry() - int(tlo->height()*squareRatioY)/2 && _p->ry() < p2.ry() + int(tlo->height()*squareRatioY)/2 )
            {

             qInfo()<<"--------------------"<<(*it)._position<<"--------------------\n";
            }
        }
}

void BoardWidget::mousePressEvent(QMouseEvent *event)
{
    qInfo()<<"mouse clicked! on: "<<*_p;
//    delete piece;
   // piece->
   QPoint tmpPoint(int((tlo->width()*boardRatioX)+4*tlo->width()*squareRatioX),int(tlo->height()*boardRatioY+3*tlo->width()*squareRatioY));

   if(_p->rx() > tmpPoint.rx() - int(tlo->width()*squareRatioX)/2 && _p->rx() < tmpPoint.rx() + int(tlo->width()*squareRatioX)/2 &&
      _p->ry() > tmpPoint.ry() - int(tlo->height()*squareRatioY)/2 && _p->ry() < tmpPoint.ry() + int(tlo->height()*squareRatioY)/2 )
   {

    piece.reset(new QImage(":/board_img/piece_png_act"));
   }

}

void BoardWidget::mouseReleaseEvent(QMouseEvent *event)
{

     piece.reset (new QImage(":/board_img/piece_png"));
//    qInfo()<<"mouse clicked!";
}


void BoardWidget::resizeEvent(QResizeEvent* event)
{
    SquarePoint tmpSquare;
    int tmp;

    QPainter p2(this);
//    qInfo()<<height()<<"    "<<width();
    const double _ScaleY=height()/static_cast<double>(tlo->height());
    const double _ScaleX=width()/static_cast<double>(tlo->width());


    p2.scale(_ScaleX,_ScaleY);
    p2.drawRect(0,0,width()+1, height()+1);
    p2.drawImage(0,0, *tlo);
//    piece->
//    p2.scale(_ScaleX/1.7,_ScaleY/1.7)

    QImage draw = piece->scaled(int(tlo->width()*squareRatioX),int(tlo->height()*squareRatioY));
//    qInfo()<<"squareX"<<int(width()*0.1)<<"squareY"<<int(height()*0.1);
    p2.drawImage(int((tlo->width()*boardRatioX)+4*tlo->width()*squareRatioX),int(tlo->height()*boardRatioY+3*tlo->width()*squareRatioY), draw);

    for(int i=0; i<=7; ++i)
    {

        for(int j=1; j<=4; ++j)
        {
            i%2==0 ?  tmp = (2*j)-1 : tmp = (2*(j-1));
            tmpSquare._position = 4*i + j;
            tmpSquare._qPoint.setX(int((tlo->width()*boardRatioX)+tmp*tlo->width()*squareRatioX));
            tmpSquare._qPoint.setY(int((tlo->height()*boardRatioY)+i*tlo->height()*squareRatioY));



            _squaresCoordsList.push_back(tmpSquare);
        }
    }
    update();
}

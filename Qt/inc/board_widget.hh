#ifndef BOARDWIDGET_HH
#define BOARDWIDGET_HH

#include <QObject>
#include <QWidget>
#include <QImage>
#include <QTimer>
#include <QSpinBox>
#include <QPainter>
#include<QPaintEvent>
#include<QPoint>
#include<memory>
#include "checkersboard.hh"
class BoardWidget : public QWidget
{
    struct SquarePoint
    {
      int _position;
      QPoint _qPoint;
    };
    typedef std::list<SquarePoint> _sqrPointList;
    typedef  std::unique_ptr<QImage>_uptrImgTpDef;

    static constexpr float boardRatioX = 0.066, boardRatioY = 0.068, squareRatioX  = 0.109, squareRatioY  = 0.10865;

    Q_OBJECT
    const QImage *tlo= new QImage(":/board_img/board_png");
    _uptrImgTpDef  piece;
    _sqrPointList _squaresCoordsList;
    QTimer *_boardTimer;
    QPoint *_p;
    CheckersBoard _board;

//    QPoint computePosition(int pose){ return QPoint(int(tlo->width()*boardRatioX)pose,int(tlo->height()*boardRatioY))}
public:
    explicit BoardWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent* event);

signals:

public slots:
    void timerEventHandler();
};

#endif // BOARDWIDGET_HH

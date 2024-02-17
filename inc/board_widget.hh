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
class BoardWidget : public QWidget
{
    Q_OBJECT
    const QImage *tlo= new QImage(":/board_img/board_png");
    const QImage *piece= new QImage(":/board_img/board_png");
    QTimer *_boardTimer;
    QPoint *_p;
public:
    explicit BoardWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:

public slots:
    void timerEventHandler();
};

#endif // BOARDWIDGET_HH

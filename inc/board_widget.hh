#ifndef BOARDWIDGET_HH
#define BOARDWIDGET_HH

#include <QObject>
#include <QWidget>
#include <QImage>
#include <QTimer>
#include <QSpinBox>
#include <QPainter>
#include<QPaintEvent>

class BoardWidget : public QWidget
{
    Q_OBJECT
    const QImage *tlo= new QImage(":/board_img/board_png");
public:
    explicit BoardWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
signals:

};

#endif // BOARDWIDGET_HH

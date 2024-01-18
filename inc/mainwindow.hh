#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_boardSliderX_valueChanged(int value);

    void on_boardSliderY_valueChanged(int value);

    void on_boardSliderZ_valueChanged(int value);

//signals
signals:
    void emitXval(int val);
    void emitYval(int val);
    void emitZval(int val);

//    void
private:
    Ui::MainWindow *ui;
    int xslide, yslide, zslide;
};
#endif // MAINWINDOW_H

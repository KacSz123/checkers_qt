#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "boardglwidget.hh"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(this,SIGNAL(emitXval(int)),ui->openGLWidget, SLOT(setXangle(int)));
    connect(this,SIGNAL(emitYval(int)),ui->openGLWidget, SLOT(setYangle(int)));
    connect(this,SIGNAL(emitZval(int)),ui->openGLWidget, SLOT(setZangle(int)));
//    ui->BoardGLWidget(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_boardSliderX_valueChanged(int value)
{
    if (value != xslide) {
        xslide = value;
        emit emitXval(value);
        qInfo()<<ui->openGLWidget->getX();
//        emit on_boardSliderX_valueChanged(value);

//    ui->openGLWidget->DrawChildren();
//        this->DrawChildren();
    }

}

void MainWindow::on_boardSliderY_valueChanged(int value)
{
    if (value != yslide) {
        yslide = value;
        emit emitYval(value);
//        emit on_boardSliderY_valueChanged(value);
    }
    this->update();
}

void MainWindow::on_boardSliderZ_valueChanged(int value)
{    if (value != zslide) {
        zslide = value;
        emit emitZval(value);
//        emit on_boardSliderZ_valueChanged(value);
    }
    this->update();
}

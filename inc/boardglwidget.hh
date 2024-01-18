#ifndef BOARDGLWIDGET_H
#define BOARDGLWIDGET_H

#include <QObject>
#include <QWidget>
#include<QGLWidget>
#include <QOpenGLWidget>
#include<QSurface>
#include<Qt3DRender>
#include<Qt3DCore>
#include<QEntity>
#include<QPalette>
#include<QColor>

#include<QtOpenGL>
#include<QOpenGLFunctions>
#include<GL/glu.h>
#include<QSurface>

#define OPENGL_MAX_W
#define OPENGL_MIN_W
#define OPENGL_MAX_H
#define OPENGL_MIN_H

QT_FORWARD_DECLARE_CLASS(QOpenGLShaderProgram)



class BoardGLWidget : public QOpenGLWidget
{
   private:
     Q_OBJECT
    bool m_core;
    static bool m_transparent;
    QOpenGLContext *context;
    QOpenGLFunctions *openGLfun;
    float rotX, rotY, rotZ;

//    QTimer *timer;
    //    QSurface format;
    public slots:
    void setXangle(int val)
    {
        rotX = val;

//        qInfo()<<"rotx"<<rotX;
        this->update();
    }
    void setYangle(int val)
    {
    rotY = val;
//    qInfo()<<"roty"<<rotY;
    this->update();
    }
    void setZangle(int val)
    {
        rotZ = val;
       this->update();

//        qInfo()<<"rotz"<<rotY;
    }
public:
   int getX(){return rotX;}
    BoardGLWidget(QWidget *parent = nullptr) : QOpenGLWidget(parent),rotX{0},rotY{0},rotZ{0}
    {

        QSurfaceFormat formate;
    formate.setProfile(QSurfaceFormat::CompatibilityProfile);
    formate.setVersion(2,1);
    setFormat(formate);
//    format

////    DrawWindowBackground();
    context = new QOpenGLContext;
    context->setFormat(formate);
    context->create();

    openGLfun = context->functions();

    }

    protected:
    virtual void initializeGL()
    {
        glEnable(GL_DEPTH_TEST);
        resizeGL(this->width(), this->height());
//        paintGL();
    };
   virtual void resizeGL(int w, int h)
    {
        //set ViewPort
        //set viewport

        glViewport(0,0,w,h);

        qreal aspectratio = qreal(w)/qreal(h);

        //init projection martix

        glMatrixMode(GL_PROJECTION);

        glLoadIdentity();



        gluPerspective(75, aspectratio, 0.1, 400000000);

        //initialize model view matrix

        glMatrixMode(GL_MODELVIEW);

        glLoadIdentity();

    };
    void paintGL();
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);
    void updateAnimation();
};

#endif // BOARDGLWIDGET_H

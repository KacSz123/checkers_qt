#include "boardglwidget.hh"

//bool BoardGLWidget::m_transparent = false;

void BoardGLWidget::paintGL()
{
    glClearColor(0.39f,0.58f,0.93f,1.f);

       glClear(GL_COLOR_BUFFER_BIT);
       glMatrixMode(GL_MODELVIEW);
       glLoadIdentity();
       //3d transformation
       qInfo()<<"tutaj!";
           glTranslatef(-0.0,-0.0,-3);

           qInfo()<<" "<<rotX<<""<<rotY<<" "<<rotZ;
           glRotatef(rotX,1.0,0.0,0.0);
           glRotatef(rotY,0.0,1.0,0.0);
           glRotatef(rotZ,0.0,0.0,1.0);

        //FRONT

           glBegin(GL_POLYGON);
           glColor3f(0.0,0.0,0.0);
           glVertex3f(0.5,-0.5,-0.5);
           glVertex3f(0.5,0.5,-0.5);
           glVertex3f(-0.5,0.5,-0.5);
           glVertex3f(-0.5,-0.5,-0.5);
           glEnd();

           //BACK

           glBegin(GL_POLYGON);
           glColor3f(0.0,1.0,0.0);
           glVertex3f(0.5,-0.5,0.5);
           glVertex3f(0.5,0.5,0.5);
           glVertex3f(-0.5,0.5,0.5);
           glVertex3f(-0.5,-0.5,0.5);
           glEnd();

           //RIGHT

           glBegin(GL_POLYGON);
           glColor3f(1.0,0.0,1.0);
           glVertex3f(0.5,-0.5,-0.5);
           glVertex3f(0.5,0.5,-0.5);
           glVertex3f(0.5,0.5,0.5);
           glVertex3f(0.5,-0.5,0.5);

           glEnd();

           //LEFT

           glBegin(GL_POLYGON);
           glColor3f(1.0,1.0,0.0);
           glVertex3f(-0.5,-0.5,0.5);
           glVertex3f(-0.5,0.5,0.5);
           glVertex3f(-0.5,0.5,-0.5);
           glVertex3f(-0.5,-0.5,-0.5);
           glEnd();

           //TOP

           glBegin(GL_POLYGON);
           glColor3f(0.0,0.0,1.0);
           glVertex3f(0.5,0.5,0.5);
           glVertex3f(0.5,0.5,-0.5);
           glVertex3f(-0.5,0.5,-0.5);
           glVertex3f(-0.5,0.5,0.5);
           glEnd();

           //BOTTOM

           glBegin(GL_POLYGON);
           glColor3f(1.0,0.0,0.0);
           glVertex3f(0.5,-0.5,-0.5);
           glVertex3f(0.5,-0.5,0.5);
           glVertex3f(-0.5,-0.5,0.5);
           glVertex3f(-0.5,-0.5,-0.5);
           glEnd();

           glFlush();


};
void BoardGLWidget::resizeEvent(QResizeEvent *event)
{
    resizeGL(this->width(),this->height());
       this->update();

};
void BoardGLWidget::paintEvent(QPaintEvent *event)
{
    paintGL();
};
void BoardGLWidget::updateAnimation()
{
    update();
}

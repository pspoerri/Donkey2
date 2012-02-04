#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QtOpenGL>

class GLWidget : public QGLWidget
{
public:
    GLWidget();

    float rotX, rotY, rotZ; //i want access these variable so public
    void resizeGL(int width, int height);
    short int col;

protected:
    void initializeGL();
    void paintGL();
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void timerEvent(QTimerEvent *event);

private:


};

#endif // GLWIDGET_H

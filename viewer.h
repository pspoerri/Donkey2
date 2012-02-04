#ifndef VIEWER_H
#define VIEWER_H

#include <QGLViewer/qglviewer.h>
#include <QMainWindow>

#include "dataset.h"
#include "vcamera.h"

class Viewer : public QGLViewer
{
public:
    vCamera cam;
    int frame;
    Dataset *dataset;
    GLuint texture[1];
    int speed;
    Viewer() {
        dataset = 0;
        frame = 0;
        speed = 0;
    }



protected:
    virtual void init();
    virtual void draw();
    virtual void animate();
    virtual QString helpString() const;
};

#endif // VIEWER_H

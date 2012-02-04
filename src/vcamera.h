#ifndef VCAMERA_H
#define VCAMERA_H

#include <QGLViewer/camera.h>

class vCamera : public qglviewer::Camera {
   virtual float zNear() const { return 0.001; };
   virtual float zFar() const { return 1000000.0; };
};

#endif // VCAMERA_H

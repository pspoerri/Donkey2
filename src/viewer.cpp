// This file belongs to Donkey²: Yet another XYZ OpenGL Dataviewer
//     https://github.com/moeeeep/donkey2
// Copyright (C) 2011  Pascal Spörri <pascal@moeeeep.com>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#define GL_GLEXT_PROTOTYPES



//#include <GL/glew.h>
#include "viewer.h"
//#include <GL/glut.h>

//#include <GL/gl.h>
//#include <GL/glx.h>
//#include <GL/glu.h>

#include <GL/glext.h>

#include <QCoreApplication>

using namespace std;
using namespace qglviewer;


void Viewer::init() {
//    if (!glutExtensionSupported("GL_ARB_point_sprite")) {
//        qDebug() << "GL_ARB_point_sprite required....";
//        exit(EXIT_FAILURE);
//    }
//    if (!glutExtensionSupported("GL_ARB_point_parameters")) {
//        qDebug() << "GL_ARB_point_parameters required....";
//        exit(EXIT_FAILURE);
//    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glAccum(GL_RETURN, 0.95f);

    // Clear the accumulation buffer (don't worry, we re-grab the screen into the accumulation buffer after drawing our current frame!)
    glClear(GL_ACCUM_BUFFER_BIT);
    glClearAccum(0.0f, 0.0f, 0.0f, 0.0f);


    glDisable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);



    float quadratic[3]  = { 1.0, 0.0, 0.01 };
    float linear[3]  = { 0.0, 1, 0.0 };
    float constant[3]  = { 0.01, 0.0, 0.0 };

    glPointParameterfvARB(GL_POINT_DISTANCE_ATTENUATION_ARB, quadratic);
    float maxSize = 30.0f;
//    glGetFloatv( GL_POINT_SIZE_MAX_ARB, &maxSize );
    glPointSize( maxSize );
    glPointParameterfARB( GL_POINT_SIZE_MAX_ARB, maxSize );
    glPointParameterfARB( GL_POINT_SIZE_MIN_ARB, 3.0f );

//    QImage b("particle.bmp");
    qDebug() << QCoreApplication::applicationDirPath();
    QImage b(QCoreApplication::applicationDirPath() + "/" + "star128.png");

    QImage t;
    t = QGLWidget::convertToGLFormat(b);
    glGenTextures(1, texture);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, t.width(), t.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, t.bits());
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvf(GL_POINT_SPRITE_ARB, GL_COORD_REPLACE_ARB, GL_TRUE);


    setCamera(&cam);
    startAnimation();
}

void Viewer::draw() {
    if (dataset == NULL) {
        return;
    }
    glDisable(GL_LIGHTING);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glAccum(GL_RETURN, 0.95f);
    glClear(GL_ACCUM_BUFFER_BIT);

    glDepthMask(GL_FALSE);
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_POINT_SPRITE_ARB);
    glColor4f(1.0f, 1.0f, 0.1f, 0.7f);

    glBegin(GL_POINTS);
    dataset->timesteps[frame].draw();
    glEnd();
    glDisable(GL_POINT_SPRITE_ARB);
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);
    glAccum(GL_ACCUM, 0.5f);

    glEnable(GL_LIGHTING);

}

void Viewer::animate() {
    if (dataset != NULL) {
//        qDebug() << frame << dataset->frames;

        frame = (frame+1) % (dataset->frames);
        if (frame == 0) {
            glClear(GL_ACCUM_BUFFER_BIT);
            glClearAccum(0.0f, 0.0f, 0.0f, 0.0f);

        }
        setSceneRadius(dataset->timesteps[frame].radius);
        Vec vec;
        vec.x = dataset->timesteps[frame].center.x;
        vec.x = dataset->timesteps[frame].center.y;
        vec.x = dataset->timesteps[frame].center.z;
        setSceneCenter(vec);
    }
}

QString Viewer::helpString() const
{
  QString text("<h2>Donkey2</h2>");
  return text;
}

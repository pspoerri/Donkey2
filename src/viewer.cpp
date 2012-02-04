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

#include "viewer.h"

using namespace std;
using namespace qglviewer;


void Viewer::init() {
    glDisable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);

    glEnable(GL_TEXTURE_2D);

    QImage b("particle.bmp");

    QImage t;
    t = QGLWidget::convertToGLFormat(b);
    glGenTextures(1, texture);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, t.width(), t.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, t.bits());
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);


    glEnable(GL_TEXTURE_2D);

    setCamera(&cam);
    startAnimation();
}

void Viewer::draw() {
    if (dataset == NULL) {
//        drawSpiral();
        return;
    }

//    glBegin(GL_POINTS);
    glPushMatrix();


    float modelview[16];
    float3 right;
    float3 up;
    glGetFloatv(GL_MODELVIEW_MATRIX, modelview);

    right.x = modelview[0];
    right.y = modelview[4];
    right.z = modelview[8];

    up.x = modelview[1];
    up.y = modelview[5];
    up.z = modelview[9];

    float3 l1 = {right.x + up.x,
                 right.y + up.y,
                 right.z + up.z};
    float3 l2 = {right.x - up.x,
                 right.y - up.y,
                 right.z - up.z};
    dataset->timesteps[frame].draw(l1, l2);
//    glEnd();
    glPopMatrix();
}

void Viewer::animate() {
    if (dataset != NULL) {
//        qDebug() << frame << dataset->frames;
        frame = (frame+1) % (dataset->frames);

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

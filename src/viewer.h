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

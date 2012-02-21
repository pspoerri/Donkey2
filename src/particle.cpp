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

#include "particle.h"

#include <QGLViewer/qglviewer.h>
#include <math.h>
void Particle::draw(float maxW) {
//    glColor4f(w/maxW, w/maxW, 1.0f, 1.0f);
    float k = w/maxW;
    float d = k;
    if (maxW - 1.0f < 0.001)
        d = 0.0;
    glColor4f(1.0, k, d, 0.3+log(1.0+k)/2.0);
    glVertex3f(x, y, z);
}

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

void Particle::draw(float3 l1, float3 l2, float maxW) {
//    l1 = right + up
//    l2 = right - up
//    a = center - (right + up) * size;
//    b = center + (right - up) * size;
//    c = center + (right + up) * size;
//    d = center - (right - up) * size;

    glColor3f(w/maxW, w/maxW, 1.0);
//    glVertex3f(x, y, z);
//    float w05 = 0.5f*w;
    float w05 = 1.0;
    glBegin(GL_TRIANGLE_STRIP);             // Build Quad From A Triangle Strip
//    glTexCoord2d(1,1); glVertex3f(x+w05,y+w05,z); // Top Right
//    glTexCoord2d(0,1); glVertex3f(x-w05,y+w05,z); // Top Left
//    glTexCoord2d(1,0); glVertex3f(x+w05,y-w05,z); // Bottom Right
//    glTexCoord2d(0,0); glVertex3f(x-w05,y-w05,z); // Bottom Left

    glTexCoord2d(1,1);
    glVertex3f(x + l1.x*w05,
               y + l1.y*w05,
               z + l1.z*w05);

    glTexCoord2d(0,1);
    glVertex3f(x - l2.x*w05,
               y - l2.y*w05,
               z - l2.z*w05);

    glTexCoord2d(1,0);
    glVertex3f(x + l2.x*w05,
               y + l2.y*w05,
               z + l2.z*w05);

    glTexCoord2d(0,0);
    glVertex3f(x - l1.x*w05,
               y - l1.y*w05,
               z - l1.z*w05);


    glEnd();
}

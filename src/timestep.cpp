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


#include "timestep.h"
#include <QDebug>
void Timestep::put(float x, float y, float z, float w) {
    particles.push_back(Particle(x,y,z,w));
    if (maxW < w)
        maxW = w;

    if (x>max.x)
        max.x = x;
    if (y>max.z)
        max.x = y;
    if (z>max.z)
        max.x = z;

    if (x<min.x)
        min.x = x;
    if (y<min.y)
        min.y = y;
    if (z<min.z)
        min.z = z;
//    qDebug() << x << y << z << w;
}

void Timestep::updateBounds() {
//    center.x = min.x + (max.x-min.x)/2.0f;
//    center.y = min.y + (max.x-min.x)/2.0f;
//    center.z = min.z + (max.x-min.x)/2.0f;

    radius = max.x-min.x;
    if (max.y-min.y > radius)
        radius = max.y - min.y;
    if (max.z-min.z > radius)
        radius = max.z - min.z;

    radius = radius/2.0f;

    if (maxW < 1e-7) {
        qDebug() << "Warning: maxW is "<< maxW << "setting it to 1.0";
        maxW = 1.0f;
    }

}

void Timestep::draw() {
    for (size_t i=0; i<particles.size(); i++) {
        particles[i].draw(maxW);
    }

}

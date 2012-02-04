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

#ifndef TIMESTEP_H
#define TIMESTEP_H


#include <QDebug>
#include "datatypes.h"
#include <vector>
#include "particle.h"
#include <limits>

class Timestep
{
public:
    std::vector<Particle> particles;
    float3 min;
    float3 max;
    float radius;
    float3 center;
    float maxW;
    Timestep() {
        maxW = 0.0;
        float minf = std::numeric_limits<float>::min();
        float maxf = std::numeric_limits<float>::max();

        max.x = minf;
        max.y = minf;
        max.z = minf;

        min.x = maxf;
        min.y = maxf;
        min.z = maxf;
    }

    void put(float x, float y, float z, float w);
    void draw(float3 l1, float3 l2);
    void updateBounds();

};

#endif // TIMESTEP_H

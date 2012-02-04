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

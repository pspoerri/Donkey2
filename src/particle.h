#ifndef PARTICLE_H
#define PARTICLE_H


#include "datatypes.h"
class Particle
{
public:
    float x,y,z;
    float w;
    Particle(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = 1.0f;
    }
    Particle(float x, float y, float z, float w) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }

    void draw(float3 l1, float3 l2, float maxW);
};

#endif // PARTICLE_H

#include "timestep.h"

void Timestep::put(float x, float y, float z, float w) {
    particles.push_back(Particle(x,y,z,w));
    if (maxW > w)
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
}

void Timestep::draw(float3 l1, float3 l2) {
    for (size_t i=0; i<particles.size(); i++) {
        particles[i].draw(l1, l2, maxW);
    }

}

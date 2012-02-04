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

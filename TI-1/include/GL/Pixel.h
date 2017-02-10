#ifndef GL_PIXEL_H
#define GL_PIXEL_H

#include "definitions.h"

struct Pixel {
    int x;
    int y;

    Pixel(const int x, const int y);
    int initialPosition(const int screenWidth);
};

#endif //GL_PIXEL_H

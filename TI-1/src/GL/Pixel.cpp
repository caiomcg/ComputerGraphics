#include "Pixel.h"

Pixel::Pixel(const int x, const int y) {
    this->x = x;
    this->y = y;
}

int Pixel::initialPosition(const int screenWidth) {
    return x*4 + y*screenWidth*4;
}

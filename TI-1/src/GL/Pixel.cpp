#include "Pixel.h"

Pixel::Pixel(const int x, const int y) {
    this->x = x;
    this->y = y;
}

int Pixel::initialPosition(const int screenWidth) {
    return (x + (y * screenWidth)) * 4;
}

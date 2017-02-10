#include "Pixel.h"

Pixel::Pixel(const int x, const int y) {
    this->x = x;
    this->y = y;
}

int Pixel::initialPosition() {
    return (x + (y * IMAGE_WIDTH)) * 4;
}

bool Pixel::isValid() const {
    if (x >= 0 && x <= IMAGE_WIDTH && y >=0 && y <= IMAGE_HEIGHT){
        return true;
    }

    return false;
}

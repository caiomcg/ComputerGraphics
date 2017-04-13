#include "Vertex.h"

Vertex::Vertex(const int x, const int y) : x(x), y(y), color(Color(0,0,0,0)) {}

Vertex::Vertex(const int x, const int y, const Color color) : x(x), y(y), color(color) {}

int Vertex::initialPosition() {
    return (x + (y * IMAGE_WIDTH)) * 4;
}

bool Vertex::isValid() const {
    if (x >= 0 && x <= IMAGE_WIDTH && y >=0 && y <= IMAGE_HEIGHT){
        return true;
    }

    return false;
}

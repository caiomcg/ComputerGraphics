#ifndef GL_VERTEX_H
#define GL_VERTEX_H

#include "definitions.h"
#include "Color.h"

struct Vertex {
    int x;
    int y;
    Color color;

    Vertex(const int x, const int y);
    Vertex(const int x, const int y, const Color color);
    int initialPosition();
    bool isValid() const;
};

#endif //GL_VERTEX_H

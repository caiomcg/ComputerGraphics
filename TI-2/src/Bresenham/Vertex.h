#ifndef VERTEX_H
#define VERTEX_H

#include "definitions.h"
#include <stdexcept>

class Vertex {
private:
    int* position;
    int* RGBA;

public:
    Vertex(int x, int y, int* RGBA);
    Vertex(int x, int y);
    ~Vertex();
    void setPosition (int x, int y);
    void setColor (int* RGBA);
    int* getPosition() const;
    int* getColor() const;
    int getX() const;
    int getY() const;
    void setY(int y);
    void setX(int x);
};

#endif

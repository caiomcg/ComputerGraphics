#ifndef ROTATION_H
#define ROTATION_H

#include <cmath>

#include "Matrix.h"

class Rotation : public Matrix {
private:
    const double PI = 3.14159;
public:

    Rotation(const int xDim, const int yDim);

    Rotation* rotate(const double angle, const Axis axis);
};

#endif

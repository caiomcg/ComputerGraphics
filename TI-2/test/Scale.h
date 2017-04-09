#ifndef SCALE_H
#define SCALE_H

#include "Matrix.h"

class Scale : public Matrix {
public:
    Scale(const int xDim, const int yDim);

    Scale* xFactor(double factor);
    Scale* yFactor(double factor);
    Scale* zFactor(double factor);
};
#endif

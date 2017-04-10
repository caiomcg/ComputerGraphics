#include "Scale.h"

Scale::Scale(const int xDim, const int yDim) : Matrix(xDim, yDim){}

Scale* Scale::factor(double factor, Axis axis) {
    if (axis == Axis::X) {
        this->matrix[0][0] = factor;
    } else if (axis == Axis::Y) {
        this->matrix[1][1] = factor;
    } else {
        this->matrix[2][2] = factor;
    }

    return this;
}

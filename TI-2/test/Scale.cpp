#include "Scale.h"

Scale::Scale(const int xDim, const int yDim) : Matrix(xDim, yDim){}

Scale* Scale::xFactor(double factor) {
    this->matrix[0][0] = factor;
    return this;
}
Scale* Scale::yFactor(double factor) {
    this->matrix[1][1] = factor;
    return this;
}
Scale* Scale::zFactor(double factor) {
    this->matrix[2][2] = factor;
    return this;
}

#include "Rotation.h"
#include <iostream>

Rotation::Rotation(const int xDim, const int yDim) : Matrix(xDim, yDim) {}

Rotation* Rotation::rotate(const double angle, const Axis axis) {
    double cossine = cos(angle * PI / 180.0);
    double sine = sin(angle * PI / 180.0);
    if (axis == Axis::X) {
        std::cout << "X" << std::endl;
        this->matrix[1][1] = cossine;
        this->matrix[1][2] = -sine;
        this->matrix[2][1] = sine;
        this->matrix[2][2] = cossine;
    } else if (axis == Axis::Y) {
        std::cout << "Y" << std::endl;
        this->matrix[0][0] = cossine;
        this->matrix[0][2] = sine;
        this->matrix[2][0] = -sine;
        this->matrix[2][2] = cossine;
    } else {
        std::cout << "Z" << std::endl;
        this->matrix[0][0] = cossine;
        this->matrix[0][1] = -sine;
        this->matrix[1][0] = sine;
        this->matrix[1][1] = cossine;
    }
}

//
// Created by caiomcg on 10/04/17.
//

#include "Translation.h"

Translation::Translation(const int xDim, const int yDim) : Matrix(xDim, yDim) {}

void Translation::translate(double amount, Axis axis) {
    if (axis == Axis::X) {
        matrix[0][3] = amount;
    } else if (axis == Axis::Y) {
        matrix[1][3] = amount;
    } else {
        matrix[2][3] = amount;
    };
}
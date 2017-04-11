//
// Created by caiomcg on 10/04/17.
//

#ifndef TRANSLATION_H
#define TRANSLATION_H

#include "Matrix.h"

class Translation : public Matrix {
public:
    Translation(const int xDim, const int yDim);

    void translate(double amount, Axis axis);
};
#endif //TRANSLATION_H

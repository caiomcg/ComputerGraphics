#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <string>

enum Axis {
    X,
    Y,
    Z
};

class Matrix {
protected:
    int xDim;
    int yDim;

    std::vector<std::vector<double> > matrix;

private:
    void createIdentityMatrix();

public:
    Matrix(const int xDim, const int yDim);
    void setMatrix(std::vector<std::vector<double> > matrix);
    Matrix* multiply(Matrix* matrix) const;
    Matrix* divide(Matrix* matrix, const double scalar) const;

    std::vector<std::vector<double> > getMatrix() const;
    std::string toString();
};
#endif

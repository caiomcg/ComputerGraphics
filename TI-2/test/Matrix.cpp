#include "Matrix.h"

void Matrix::createIdentityMatrix() {
    matrix = std::vector<std::vector<double> >(xDim, std::vector<double>(yDim, 0.0)); //Initialize with zeros
    for (int i = 0; i < xDim; i++) {
        matrix[i][i] = 1.0;
    }
}

Matrix::Matrix(const int xDim, const int yDim) : xDim(xDim), yDim(yDim) {
    createIdentityMatrix();
}

void Matrix::setMatrix(std::vector<std::vector<double> > matrix) {
    this->matrix = matrix;
}

Matrix* Matrix::multiply(Matrix* matrix) const {
    Matrix* newMatrix = new Matrix(xDim, yDim);
    newMatrix->setMatrix(this->matrix);
    double sum = 0.0;

    for (int i = 0; i < xDim; i++) {
        for (int j = 0; j < yDim; j++) {
            for (int k = 0; k < xDim; k++) {
                sum += this->matrix[i][k] * matrix->matrix[k][j];
            }
            newMatrix->matrix[i][j] = sum;
            sum = 0.0;
        }
    }
    return newMatrix;
}

std::string Matrix::toString() {
    std::string out;

    for (int i = 0; i < xDim; i++) {
        out += "| ";
        for (int j = 0; j < yDim; j++) {
            out += std::to_string(matrix[i][j]) + " ";
        }
        out += "|\n";
    }
    return out;
}

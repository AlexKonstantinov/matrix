#ifndef _MY_FILE_H_

#define _MY_FILE_H_

#ifndef __cplusplus
#error Need C++-compile to process this file
#endif
#include <iostream>

class Matrix {
public:
    Matrix(unsigned rowNumber, unsigned colNumber) : rn(rowNumber) , cn(colNumber) {
        if (rowNumber == 0 || colNumber == 0)
            throw std::invalid_argument("Matrix constructor has 0 size");
        matrix = new double[rowNumber*colNumber];
        for (int index = 0; index < rowNumber*colNumber; index++) {
            this->matrix[index] = 0;
        }
    };
    ~Matrix() {
        std::cout << "Memory has been cleaned. Good bye." << std::endl;
        delete[] this->matrix;
    };
    double& operator() (unsigned rowNumber, unsigned colNumber) const{
        if (rowNumber >= rn || colNumber >= cn)
            throw std::invalid_argument("Matrix subscript out of bounds");
        return this->matrix[cn*rowNumber + colNumber];
    };
    Matrix& operator+(const Matrix& rhs) {
        Matrix *result = new Matrix(this->rn, this->cn);
        for (int index = 0, currentRowNum = 0; index < this->rn * this->cn; index++, currentRowNum = index/(this->rn)) {
            result->matrix[index] = (*this)(currentRowNum, index - currentRowNum * cn ) + rhs(currentRowNum, index - currentRowNum * cn );
        }
        return *result;
    };
    Matrix& operator+=(const Matrix& rhs) {
        for (int index = 0, currentRowNum = 0; index < this->rn * this->cn; index++, currentRowNum = index/(this->rn)) {
            this->matrix[index] = (*this)(currentRowNum, index - currentRowNum * cn ) + rhs(currentRowNum, index - currentRowNum * cn );
        }
        return *this;
    };
private:
    double *matrix;
    unsigned rn, cn;
};

#endif
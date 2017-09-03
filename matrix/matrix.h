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
        rowVector = new double[colNumber];
        colVector = new double[rowNumber];
        for (int index = 0; index < rowNumber*colNumber; index++) {
            this->matrix[index] = 0;
        }
    };
    ~Matrix() {
        std::cout << "Memory has been cleaned. Good bye." << std::endl;
        delete[] this->matrix;
        delete[] this->rowVector;
        delete[] this->colVector;
    };
    double& operator() (unsigned rowNumber, unsigned colNumber) const{
        if (rowNumber >= rn || colNumber >= cn)
            throw std::invalid_argument("Matrix subscript out of bounds");
        return this->matrix[cn*rowNumber + colNumber];
    };
    double* operator() (unsigned rowNumber) const{
        for (int index=0; index < cn; index++) {
            rowVector[index] = matrix[rowNumber * cn + index];
        }
        return this->rowVector;
    }
    double* operator[] (unsigned colNumber) const{
        for (int index=0; index < rn; index++) {
            colVector[index] = matrix[colNumber + rn * index];
        }
        return this->colVector;
    }
    const Matrix& operator+(const Matrix& rhs) {
        if (rn != rhs.getRowCount() || cn != rhs.getColCount())
            throw std::invalid_argument("Unequal matrix size");
        Matrix *result = new Matrix(this->rn, this->cn);
        for (int index = 0, currentRowNum = 0; index < this->rn * this->cn; index++, currentRowNum = index/(this->rn)) {
            result->matrix[index] = (*this)(currentRowNum, index - currentRowNum * cn ) + rhs(currentRowNum, index - currentRowNum * cn );
        }
        return *result;
    };
    const Matrix& operator+=(const Matrix& rhs) {
        if (rn != rhs.getRowCount() || cn != rhs.getColCount())
            throw std::invalid_argument("Unequal matrix size");
        for (int index = 0, currentRowNum = 0; index < this->rn * this->cn; index++, currentRowNum = index/(this->rn)) {
            this->matrix[index] = (*this)(currentRowNum, index - currentRowNum * cn ) + rhs(currentRowNum, index - currentRowNum * cn );
        }
        return *this;
    };
    const Matrix& operator*(const Matrix& rhs) {
        if (cn != rhs.getRowCount())
            throw std::invalid_argument("Left matrix ColNumber must be equal to the right matrix RowNumber");
        Matrix *result = new Matrix(rn, rhs.getColCount());
        for (int rowIndex = 0; rowIndex < rn; rowIndex++) {
            for (int colIndex=0; colIndex < rhs.getColCount(); colIndex++) {
                for (int index=0; index < cn; index++) {
                    double x = (*this)(rowIndex)[index];
                    double y = rhs[colIndex][index];
                    result->matrix[rowIndex*cn + colIndex] += x * y;
                }
            }
        }
        delete[] rowVector;
        delete[] colVector;
        return *result;
    };
    const Matrix& operator*=(const Matrix& rhs) {
        if (cn != rhs.getRowCount())
            throw std::invalid_argument("Left matrix ColNumber must be equal to the right matrix RowNumber");
        Matrix *result = new Matrix(rn, rhs.getColCount());
        for (int rowIndex = 0; rowIndex < rn; rowIndex++) {
            for (int colIndex=0; colIndex < rhs.getColCount(); colIndex++) {
                for (int index=0; index < cn; index++) {
                    result->matrix[rowIndex*cn + colIndex] += (*this)(rowIndex)[index] * rhs[colIndex][index];
                }
            }
        }
        *this = *result;
        return *this;
    };
    unsigned getRowCount() const {
        return rn;
    }
    unsigned getColCount() const{
        return cn;
    }
    unsigned count() const{
        return rn*cn;
    }
private:
    double *matrix, *rowVector, *colVector;
    unsigned rn, cn;
};

#endif
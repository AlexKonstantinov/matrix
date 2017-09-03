#ifndef _MY_FILE_H_

#define _MY_FILE_H_

#ifndef __cplusplus
#error Need C++-compile to process this file
#endif
#include <iostream>

class Matrix {
public:
    Matrix(unsigned rowNumber, unsigned colNumber) {
        if (rowNumber == 0 || colNumber == 0)
            throw BadIndex("Matrix constructor has 0 size");
        this->rowNumber = rowNumber;
        this->colNumber = colNumber;
        matrix = new double[rowNumber*colNumber];
        for (int index = 0; index < rowNumber*colNumber; index++) {
            this->matrix[index] = 0;
        }
    };
/*    double** getMatrix() {
        return this->matrix;
    };
    double getMatrixElement(int rn, int cn) const {
        return this->matrix[rn][cn];
    }
    int getRowCount() const {
        return this->rowNumber;
    }
    int getColCount() const {
        return this->colNumber;
    }*/
    ~Matrix() {
        std::cout << "Memory has been cleaned. Good bye." << std::endl;
        delete[] this->matrix;
    };
    /*const Matrix& operator += (const Matrix& matrix) {
        int mColNum, mRowNum;
        mColNum = matrix.getColCount();
        mRowNum = matrix.getRowCount();
        if (this->rowNumber != mRowNum || this->colNumber != mColNum) {
            throw std::invalid_argument("Mismatch of matrixes rowcount and colcount, they must be equal");
        }
        for (int rowIndex = 0; rowIndex < this->rowNumber; rowIndex++)
        {
            for (int colIndex = 0; colIndex < this->colNumber; colIndex++)
            {
                this->matrix[rowIndex][colIndex] += matrix.getMatrixElement(rowIndex, colIndex);
            }
        }
        return *this;
    }
    Matrix& operator=(const Matrix& rMatrix) {
        int mColNum, mRowNum;
        mColNum = rMatrix.getColCount();
        mRowNum = rMatrix.getRowCount();
        double** newM;
        newM = new double* [mRowNum];
        for (int rowIndex = 0; rowIndex < mRowNum; rowIndex++)
        {
            newM[rowIndex] = new double[mColNum];
            for (int colIndex = 0; colIndex < mColNum; colIndex++)
            {
                newM[rowIndex][colIndex] = rMatrix.getMatrixElement(rowIndex, colIndex);
            }
        }
        Matrix *newMatrix = new Matrix(newM, mRowNum, mColNum);
        *this = *newMatrix;
        return *this;
    }
    friend Matrix& operator +(const Matrix& lMatrix, const Matrix& rMatrix) {
        int lColNum, lRowNum, rColNum, rRowNum;
        lColNum = lMatrix.getColCount();
        lRowNum = lMatrix.getRowCount();
        rColNum = rMatrix.getColCount();
        rRowNum = rMatrix.getRowCount();
        double** newMatrix;
        if (lRowNum != rRowNum || lColNum != rColNum) {
            throw std::invalid_argument("Mismatch of matrixes rowcount and colcount, they must be equal");
        }
        newMatrix = new double*[lRowNum];
        for (int rowIndex = 0; rowIndex < lRowNum; rowIndex++)
        {
            newMatrix[rowIndex] = new double[lColNum];
            for (int colIndex = 0; colIndex < lColNum; colIndex++)
            {
                newMatrix[rowIndex][colIndex] = lMatrix.matrix[rowIndex][colIndex] + rMatrix.getMatrixElement(rowIndex, colIndex);
            }
        }
        Matrix *newM = new Matrix(newMatrix, lRowNum, lColNum);
        return *newM;
    }*/
private:
    double *matrix;
    int rowNumber = 0, colNumber = 0;
};

#endif
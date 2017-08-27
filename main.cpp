#include <iostream>

class Matrix {
public:
    double **matrix = new double *[0];
    Matrix(double **arr, int rowNumber, int colNumber) {
        delete this->matrix;
        this->matrix = new double *[rowNumber];
        this->rowNumber = rowNumber;
        this->colNumber = colNumber;
        for (int rowIndex = 0; rowIndex < rowNumber; rowIndex++)
        {
            this->matrix[rowIndex] = new double[colNumber];
            for (int colIndex = 0; colIndex < colNumber; colIndex++)
            {
                this->matrix[rowIndex][colIndex] = arr[rowIndex][colIndex];
            }
        }
    };
    ~Matrix() {
        std::cout << "Memory has been cleaned. Good bye." << std::endl;
    };
    Matrix& operator += (const Matrix& matrix) {
        for (int rowIndex = 0; rowIndex < this->rowNumber; rowIndex++)
        {
            for (int colIndex = 0; colIndex < this->colNumber; colIndex++)
            {
                this->matrix[rowIndex][colIndex] += matrix.matrix[rowIndex][colIndex];
            }
        }

        return *this;
    }
private:

    int rowNumber = 0, colNumber = 0;

};

int main() {

    int c;
    int rn=3, cn =3;
    auto **arr =  new double *[rn];

    for (int i = 0; i < 3; i++)
    {
        arr[i] = new double[cn];
        for (int j = 0; j < 3; j++)
        {
            std::cin >> arr[i][j];
        }
    }
    Matrix matr(arr, 3, 3);
    Matrix matr2(arr, 3, 3);
    matr+=matr2;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << matr.matrix[i][j];
        }
        std::cout << std::endl;
    }
    std::cin >> c;
    return 0;
}
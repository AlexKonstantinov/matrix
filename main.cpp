#include <iostream>

int main() {

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
        Matrix& operator+(const Matrix& matrix) {
            double **tmp = new double*[rowNumber];
            for (int rowIndex = 0; rowIndex < rowNumber; rowIndex++)
            {
                tmp[rowIndex] - new double[colNumber];
                for (int colIndex = 0; colIndex < colNumber; colIndex++)
                {
                    tmp[rowIndex][colIndex] = this->matrix[rowIndex][colIndex] + matrix.matrix[rowIndex][colIndex];
                }
            }

            return *this;
        }
    private:

        int rowNumber = 0, colNumber = 0;

    };

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

    auto matrix = new Matrix(arr, 3, 3);
    auto matrix2 = new Matrix(arr, 3, 3);
    matrix+=matrix2;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << matrix->matrix[i][j];
        }
        std::cout << std::endl;
    }
    std::cin >> c;
    return 0;
}
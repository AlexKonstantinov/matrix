#include <iostream>
#include "matrix/matrix.h"

int main() {

    int c;
    int rn=3, cn =3;
    auto **arr =  new double *[rn];
    auto **arr2 = new double *[rn];

    for (int i = 0; i < 3; i++)
    {
        arr[i] = new double[cn];
        for (int j = 0; j < 3; j++)
        {
            std::cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        arr2[i] = new double[cn];
        for (int j = 0; j < 4; j++)
        {
            std::cin >> arr2[i][j];
        }
    }

    Matrix *matr = new Matrix(arr, 3, 3);
    Matrix *matr2 = new Matrix(arr2, 3, 4);
    Matrix *matr3;
    *matr+=*matr;
    *matr3 = *matr+*matr;

    try {
        *matr+=*matr2;
    }
    catch(const std::invalid_argument& e) {
        std::cout << e.what();
    }

    double **tmpp, **tmpp2;
    tmpp = matr->getMatrix();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << tmpp[i][j] << " ";
        }
        std::cout << std::endl;
    }
    tmpp2 = matr3->getMatrix();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << tmpp2[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cin >> c;
    return 0;
}
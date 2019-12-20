#include <iostream>

#include "matrix.h"

using namespace std;

// main function -
// where the execution of program begins
int main()
{
    matrix matr1(10, 10);

    matrix matr2(10, 10);

    matr1.printMatrix();
    cout << "-----------------------------------------------------------------------\n";
    matr2.printMatrix();

    // test operator+

    // matrix result = matr1 + matr2;
    //cout << "-----------------------------------------------------------------------\n";
    // result.printMatrix();

    // test operator-

    // matrix result = matr1 - matr2;
    // cout << "------------------------------------------------------------------------\n";
    // result.printMatrix();

    // test operator<
    // int **result = matr1 < 3;
    // cout << "------------------------------------------------------------------------\n";
    // for (int i = 0; i < matr1.getRow(); i++)
    // {
    //     for (int j = 0; j < matr1.getCol(); j++)
    //         printf("%d\t", result[i][j]);
    //     printf("\n");
    // }

    // test operator--


    // matrix result = -- ;
    // cout << "------------------------------------------------------------------------\n";

    return 0;
}
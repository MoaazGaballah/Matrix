#include <iostream>
#include <time.h>

#include "matrix.h"

using namespace std;

matrix::matrix()
{
    // prints hello world
    cout << "Hello World";
}

void matrix::setRow(int rows)
{
    this->row = rows;
}

int matrix::getRow() const
{
    return this->row;
}

void matrix::setCol(int columns)
{
    this->col = columns;
}

int matrix::getCol() const
{
    return this->col;
}

matrix::matrix(int rows, int columns)
{
    srand(time(NULL));

    // setting rows and columns
    this->setRow(rows);
    this->setCol(columns);

    // initalizing array at memory
    this->mat = new int *[rows];
    for (int i = 0; i < rows; ++i)
        this->mat[i] = new int[columns];

    // giving random numbers to the matrix
    int max = 9, min = 1;
    for (int i = 0; i < this->row; i++)
        for (int j = 0; j < this->col; j++)
            this->mat[i][j] = ((rand() % (int)(((max) + 1) - (min))) + (min));
}

void matrix::printMatrix()
{
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
            printf("%d\t", this->mat[i][j]);
        printf("\n");
    }
}

matrix matrix::operator+(const matrix &ma)
{
    matrix temp(this->row, this->col);

    if (this->row != ma.row || this->col != ma.col)
    {
        for (int i = 0; i < this->row; i++)
            for (int j = 0; j < this->col; j++)
                temp.mat[i][j] = this->mat[i][j];
        return temp;
    }

    else
    {
        for (int i = 0; i < this->row; i++)
            for (int j = 0; j < this->col; j++)
                temp.mat[i][j] = ma.mat[i][j] + this->mat[i][j];
    }

    return temp;
}

matrix matrix::operator-(const matrix &ma)
{
    matrix temp(this->row, this->col);
    if (this->row != ma.row || this->col != ma.col)
    {
        for (int i = 0; i < this->row; i++)
            for (int j = 0; j < this->col; j++)
                temp.mat[i][j] = this->mat[i][j];
        return temp;
    }
    else
    {
        for (int i = 0; i < this->row; i++)
            for (int j = 0; j < this->col; j++)
                temp.mat[i][j] = this->mat[i][j] - ma.mat[i][j];
    }
    return temp;
}

int **matrix::operator<(int num)
{
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {
            // if the matrix element is smaller than num (parameter)
            if (this->mat[i][j] < num)
            {
                this->mat[i][j] = 0;
            }
            else // if the matrix element is bigger than num (parameter)
            {
                this->mat[i][j] = 1;
            }
        }
    }
    return this->mat;
}

void matrix::operator--()
{
    for (int i = 0; i < this->row; i++)
        for (int j = 0; j < this->col; j++)
            this->mat[i][j] -= 1;
}

void matrix::operator++()
{
    for (int i = 0; i < this->row; i++)
        for (int j = 0; j < this->col; j++)
            this->mat[i][j] += 1;
}

std::ostream& operator<<(std::ostream& os, const matrix & m)
{
    for (int i=0; i < m.row; ++i) {
        for (int j=0; j < m.col; ++j) {
            os << m.mat[i][j] << "  " ;
        }
        os << '\n';
    }
    return os;
}

matrix::~matrix()
{
    for (int i = 0; i < this->row; ++i)
        delete[] this->mat[i];
    delete[] this->mat;
}
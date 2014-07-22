#ifndef _MATRIX_H
#define _MATRIX_H

#include <vector>
using namespace std;

class Matrix {
    private:
        vector<vector<int> > matrix;
        unsigned rows;
        unsigned cols;

    public:
        Matrix(unsigned _rows, unsigned _cols, int _init_value);
        Matrix(const Matrix& obj);
        ~Matrix();
};

#include "matrix.cpp"

#endif

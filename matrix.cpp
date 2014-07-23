#ifndef _MATRIX_CPP
#define _MATRIX_CPP

#include <vector>
#include "matrix.h"
using namespace std;

Matrix::Matrix(unsigned _rows, unsigned _cols, int _init_value) {
    rows = _rows;
    cols = _cols;

    matrix.resize(_rows);
    for(int i = 0; i < _rows; ++i) {
        matrix[i].resize(_cols, _init_value);
    }
}

Matrix::Matrix(const Matrix& obj) {
    rows = obj.rows;
    cols = obj.cols;
    matrix = obj.matrix;
}

Matrix::~Matrix() {}

// Get the number of rows of matrix
unsgined Matrix::get_rows() const {
    return this->rows;
}

// Get the number of columns of matrix
unsigned Matrix::get_cols() const {
    return this->cols;
}

#endif

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

// Addition of two matrices
Matrix Matrix::operator+(const Matrix& rhs) {
    Matrix res(rows,cols,0);

    for(unsigned i = 0;i < rows;i++) {
        for(unsigned j = 0;j < cols;j++) {
	    res(i,j) = this->matrix[i][j] + rhs(i,j);
	}
    }

    return res;
}

// Cumulative addition of this matrix with another matrix
Matrix& Matrix::operator+=(const Matrix& rhs) {
    unsigned rows = rhs.get_rows();
    unsigned cols = rhs.get_cols();

    for(unsigned i = 0;i < rows;i++) {
        for(unsigned j = 0;j < cols;j++) {
	    this->matrix[i][j] += rhs(i,j);
	}
    }
    return *this;
}

// Subtraction of two matrices
Matrix Matrix::operator-(const Matrix& rhs) {
    Matrix res(rows,cols,0);

    for(unsigned i = 0;i < rows;i++) {
        for(unsigned j = 0;j < cols;j++) {
	    res(i,j) = this->matrix[i][j] - rhs(i,j);
        }
    }

    return res;
}

// Cumulative subtraction of two matrices
Matrix& Matrix::operator-=(const Matrix& rhs) {
    unsigned rows = rhs.get_rows();
    unsigned cols = rhs.get_cols();

    for(unsigned i = 0;i < rows;i++) {
        for(unsigned j = 0;j < cols;j++) {
	    this->matrix[i][j] -= rhs(i,j);
	}
    }
    return *this;
}

// Get the number of rows of matrix
unsgined Matrix::get_rows() const {
    return this->rows;
}

// Get the number of columns of matrix
unsigned Matrix::get_cols() const {
    return this->cols;
}

#endif

#ifndef _MATRIX_CPP
#define _MATRIX_CPP

#include <iostream>
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

// Display matrix
void Matrix::Display() {
    for(unsigned i = 0; i < rows; ++i) {
        for(unsigned j = 0; j < cols; ++j) {
            cout << matrix[i][j] << "  ";
        }
        cout << "\n";
    }
}

// Addition of two matrices
Matrix Matrix::operator+(const Matrix& rhs) {
    Matrix res(rows,cols,0);

    for(unsigned i = 0;i < rows;i++) {
        for(unsigned j = 0;j < cols;j++) {
	    res.matrix[i][j] = this->matrix[i][j] + rhs.matrix[i][j];
	    }
    }
    return res;
}

// Cumulative addition of this matrix with another matrix
Matrix& Matrix::operator+=(const Matrix& rhs) {
    unsigned rows = rhs.GetNumRows();
    unsigned cols = rhs.GetNumCols();

    for(unsigned i = 0;i < rows;i++) {
        for(unsigned j = 0;j < cols;j++) {
	    this->matrix[i][j] += rhs.matrix[i][j];
	    }
    }
    return *this;
}

// Subtraction of two matrices
Matrix Matrix::operator-(const Matrix& rhs) {
    Matrix res(rows,cols,0);

    for(unsigned i = 0;i < rows;i++) {
        for(unsigned j = 0;j < cols;j++) {
	        res.matrix[i][j] = this->matrix[i][j] - rhs.matrix[i][j];
        }
    }

    return res;
}

// Cumulative subtraction of two matrices
Matrix& Matrix::operator-=(const Matrix& rhs) {
    unsigned rows = rhs.GetNumRows();
    unsigned cols = rhs.GetNumCols();

    for(unsigned i = 0;i < rows;i++) {
        for(unsigned j = 0;j < cols;j++) {
	    this->matrix[i][j] -= rhs.matrix[i][j];
	    }
    }
    return *this;
}


// Multiplication of a matrix by a scalar
void Matrix::ScalarMultiply(int scalar) {
    for(unsigned i = 0; i < rows; ++i) {
        for(unsigned j = 0; j < cols; ++j) {
            matrix[i][j] *= scalar;
        }
    }
    return;
}

// Get the number of rows of matrix
unsigned Matrix::GetNumRows() const {
    return this->rows;
}

// Get the number of columns of matrix
unsigned Matrix::GetNumCols() const {
    return this->cols;
}

// Return the row at the specified index
vector<int> Matrix::GetRow(int index) {
    return this->matrix[index];
}

// Return the column at the specified index
vector<int> Matrix::GetCol(int index) {
    vector<int> column;
    for(int i = 0; i < this->rows; ++i)
        column.push_back(this->matrix[i][index]);
    return column;
}

#endif

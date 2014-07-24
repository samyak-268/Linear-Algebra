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
	
	// Basic Matrix mathematical operations
	Matrix operator+(const Matrix& rhs);
	Matrix& operator+=(const Matrix& rhs);
	Matrix operator-(const Matrix& rhs);
	Matrix& operator-=(const Matrix& rhs);
	
	// Acessing the row and column sizes
	unsigned get_rows() const;
	unsgined get_cols() const;

};

#include "matrix.cpp"

#endif

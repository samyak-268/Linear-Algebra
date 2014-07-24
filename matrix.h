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

    // Displaying matrix
    void Display();
	
    // Basic Matrix mathematical operations
	Matrix operator+(const Matrix& rhs);
	Matrix& operator+=(const Matrix& rhs);
	Matrix operator-(const Matrix& rhs);
	Matrix& operator-=(const Matrix& rhs);
    void ScalarMultiply(int scalar);
	
	// Acessing the row and column sizes
	unsigned get_rows() const;
	unsigned get_cols() const;

};

#include "matrix.cpp"

#endif

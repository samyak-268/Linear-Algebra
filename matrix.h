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
        unsigned GetNumRows() const;
        unsigned GetNumCols() const;

        // Acessing the row and columns by indices
        vector<int> GetRow(int index);
        vector<int> GetCol(int index);

        // Matrix-Vector multiplication
        vector<int> ColVectorMultiply(vector<int> vec);
        vector<int> RowVectorMultiply(vector<int> vec);
};

#include "matrix.cpp"

#endif

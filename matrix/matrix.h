#ifndef _MATRIX_H
#define _MATRIX_H

#include <vector>
#include <string>
using namespace std;

class Matrix {
    private:
        vector<vector<double> > matrix;
        unsigned rows;
        unsigned cols;

    public:
        Matrix(unsigned _rows, unsigned _cols, double _init_value);
        Matrix(unsigned _rows, unsigned _cols, const string filename);
        Matrix(const Matrix& obj);
        ~Matrix();

        // Displaying matrix
        void Display();
	    
        // Get 
        double operator() (int r, int c) const;

        // Set
        double& operator() (int r, int c);

        // Basic Matrix mathematical operations
        Matrix operator+(const Matrix& rhs);
        Matrix& operator+=(const Matrix& rhs);
        Matrix operator-(const Matrix& rhs);
        Matrix& operator-=(const Matrix& rhs);
        void ScalarMultiply(double scalar);
        
        // Acessing the row and column sizes
        unsigned GetNumRows() const;
        unsigned GetNumCols() const;

        // Acessing the row and columns by indices
        vector<double> GetRow(int index);
        vector<double> GetCol(int index);

        // Matrix-Vector multiplication
        vector<double> ColVectorMultiply(vector<double> vec);
        vector<double> RowVectorMultiply(vector<double> vec);

        // Matrix-Matrix multiplication
        Matrix NaiveMultiply(Matrix B);
};


#endif

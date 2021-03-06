#ifndef _MATRIX_CPP
#define _MATRIX_CPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <iomanip>
#include "matrix.h"
using namespace std;

Matrix::Matrix(unsigned _rows, unsigned _cols, double _init_value)
{
    rows = _rows;
    cols = _cols;

    matrix.resize(_rows);
    for(int i = 0; i < _rows; ++i) {
        matrix[i].resize(_cols, _init_value);
    }
}

Matrix::Matrix(unsigned _rows, unsigned _cols, const string filename)
{
    rows = _rows;
    cols = _cols;
    
    matrix.resize(_rows);
    ifstream infile;
    infile.open(filename.c_str());
    
    if(infile.is_open())
    {
        cout << "File has been successfully opened!\n";
        for(int i = 0; i < _rows; ++i)
        {
            matrix[i].resize(_cols);
            for(int j = 0; j < _cols; ++j)
            {
                double entry;
                infile >> entry;
                matrix[i][j] = entry;
            }
        }
    }

    infile.close();
}

Matrix::Matrix(vector<vector<double> > _matrix) {
    rows = _matrix.size();
    cols = _matrix[0].size();

    matrix.resize(rows);
    for(int i = 0; i < rows; ++i) {
        matrix[i].resize(cols, 0);
        for(int j = 0; j < cols; ++j)
            matrix[i][j] = _matrix[i][j];
    }
}

Matrix::Matrix(const Matrix& obj)
{
    rows = obj.rows;
    cols = obj.cols;
    matrix = obj.matrix;
}

Matrix::~Matrix() {}

// Display matrix
void Matrix::Display()
{
    ios::fmtflags old_settings = cout.flags();
    int old_precision = cout.precision();

    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(4);

    for(unsigned i = 0; i < rows; ++i) {
        for(unsigned j = 0; j < cols; ++j) {
            cout << setw(10) << matrix[i][j] << "  ";
        }
        cout << "\n";
    }

    cout.flags(old_settings);
    cout.precision(old_precision);
}

// Get 
double Matrix::operator() (int r, int c) const {
    if (r >= 0 && r < rows && c >= 0 && c < cols) {
        return this->matrix[r][c];
    }
    else {
        throw out_of_range("Index out of bounds!");
    }
}
    
// Set 
double& Matrix::operator() (int r, int c) {
    if (r >= 0 && r < rows && c >= 0 && c < cols) {
        return this->matrix[r][c];
    }
    else {
        throw out_of_range("Index out of bounds!");
    }
}

// Identity matrix
void Matrix::eye() {
    vector<vector<double> >::iterator it((this->matrix).begin());

    for (; it != (this->matrix).end(); ++it) 
        fill((*it).begin(), (*it).end(), 0.0);

    for (int i = 0; i < this->rows; i++)
        this->matrix[i][i] = 1.0;
}

// Addition of two matrices
Matrix Matrix::operator+(const Matrix& rhs)
{
    Matrix res(rows,cols,0);

    for(unsigned i = 0;i < rows;i++) {
        for(unsigned j = 0;j < cols;j++) {
	    res.matrix[i][j] = this->matrix[i][j] + rhs.matrix[i][j];
	    }
    }
    return res;
}

// Cumulative addition of this matrix with another matrix
Matrix& Matrix::operator+=(const Matrix& rhs)
{
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
Matrix Matrix::operator-(const Matrix& rhs)
{
    Matrix res(rows,cols,0);

    for(unsigned i = 0;i < rows;i++) {
        for(unsigned j = 0;j < cols;j++) {
	        res.matrix[i][j] = this->matrix[i][j] - rhs.matrix[i][j];
        }
    }

    return res;
}

// Cumulative subtraction of two matrices
Matrix& Matrix::operator-=(const Matrix& rhs)
{
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
void Matrix::ScalarMultiply(double scalar)
{
    for(unsigned i = 0; i < rows; ++i) {
        for(unsigned j = 0; j < cols; ++j) {
            matrix[i][j] *= scalar;
        }
    }
    return;
}

// Get the number of rows of matrix
unsigned Matrix::GetNumRows() const
{
    return this->rows;
}

// Get the number of columns of matrix
unsigned Matrix::GetNumCols() const
{
    return this->cols;
}

// Return the row at the specified index
vector<double> Matrix::GetRow(int index)
{
    return this->matrix[index];
}

// Return the column at the specified index
vector<double> Matrix::GetCol(int index)
{
    vector<double> column;
    for(int i = 0; i < this->rows; ++i)
        column.push_back(this->matrix[i][index]);
    return column;
}

// Multiply a matrix with a column vector
vector<double> Matrix::ColVectorMultiply(vector<double> vec)
{
    vector<double> result;
    result.resize(vec.size());
    
    if(this->cols != vec.size()) {
        cout << "Incompatible dimensions!\n";
        return result;
    }

    double partial_sum;
    for(int i = 0; i < this->rows; ++i) {
        partial_sum = 0;
        for(int j = 0; j < this->cols; ++j)
            partial_sum += (this->matrix[i][j] * vec[j]);

        result[i] = partial_sum;
    }
    return result;
}

// Multiply a row vector with a matrix
vector<double> Matrix::RowVectorMultiply(vector<double> vec)
{
    vector<double> curr_row, sum_rows;
    curr_row.resize(vec.size());
    sum_rows.resize(vec.size(), 0);

    if(this->rows != vec.size()) {
        cout << "Incompatible dimensions!\n";
        return sum_rows;
    }

    for(int i = 0; i < this->rows; ++i) {
        curr_row = GetRow(i);
        for(int j = 0; j < curr_row.size(); ++j)
            curr_row[j] = curr_row[j] * vec[i];
        for(int j = 0; j < curr_row.size(); ++j)
            sum_rows[j] += curr_row[j];
    }
    return sum_rows;
}

// Naive (ijk algorithm) for multiplying 2 matrices
Matrix Matrix::NaiveMultiply(Matrix B)
{
    int result_rows = this->rows;
    int result_cols = B.GetNumCols();
    Matrix result(result_rows, result_cols, 1);

    if(this->cols != B.GetNumRows()) {
        cout << "Incompatible dimensions!\n";
        Matrix incompatible_result(1, 1, -1);
        return incompatible_result;
    }

    for(int i = 0; i < this->rows; ++i) {
        for(int j = 0; j < B.GetNumCols(); ++j) {
            double temp = 0;
            for(int k = 0; k < this->cols; ++k) {
                temp += (this->matrix[i][k] * B.matrix[k][j]);
            }
            result.matrix[i][j] = temp;
        }
    }

    return result;
}

#endif

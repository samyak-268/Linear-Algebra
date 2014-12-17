#ifndef _GAUSSJ_CPP
#define _GAUSSJ_CPP

#include "gaussj.h"
#include <iostream>
using namespace std;

GaussJ::GaussJ(const Matrix& A_obj, const Matrix& b_obj)
    : A(A_obj), b(b_obj)
{
}

void GaussJ::scaleRow(int row_idx, double multiplier)
{
    for (int j = 0; j < A.GetNumCols(); ++j)
        A(row_idx, j) *= multiplier;
}

void GaussJ::addRows(int idx_1, int idx_2)
{
    for (int j = 0; j < A.GetNumCols(); ++j)
        A(idx_1, j) = A(idx_1, j) + A(idx_2, j);
}

void GaussJ::swapRows(int idx_1, int idx_2)
{
    int n = A.GetNumCols();
    
    double temp;
    for(int j = 0; j < n; ++j)
    {
        temp = A(idx_1, j);
        A(idx_1, j) = A(idx_2, j);
        A(idx_2, j) = temp;
    }
}

void GaussJ::displayCoeffMatrix()
{
    for(unsigned i = 0; i < A.GetNumRows(); ++i) {
        for(unsigned j = 0; j < A.GetNumCols(); ++j) {
            cout << A(i, j) << "  ";
        }
        cout << "\n";
    }
}

#endif

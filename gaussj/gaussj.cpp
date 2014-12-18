#ifndef _GAUSSJ_CPP
#define _GAUSSJ_CPP

#include "gaussj.h"
#include <iostream>
using namespace std;

GaussJ::GaussJ(const Matrix& _A, const Matrix& _b)
    : A(_A), b(_b)
{
}

Matrix GaussJ::augmentMatrix()
{
    int N = A.GetNumRows();

    vector<vector<double> > aug_matrix_vec;
    aug_matrix_vec.resize(N, vector<double>(N+1, 0.0));
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < (N+1); ++j)
        {
            if(j == N)
                aug_matrix_vec[i][j] = b(i, 0);
            else
                aug_matrix_vec[i][j] = A(i, j);
        }
    }

    Matrix aug(aug_matrix_vec);
    return aug;
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

void GaussJ::displayAugMatrix(const Matrix& aug)
{
    for(unsigned i = 0; i < aug.GetNumRows(); ++i) {
        for(unsigned j = 0; j < aug.GetNumCols(); ++j) {
            cout << aug(i, j) << "  ";
        }
        cout << "\n";
    }
}

#endif

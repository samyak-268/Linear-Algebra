#ifndef _GAUSSJ_CPP
#define _GAUSSJ_CPP

#include "gaussj.h"
#include <iostream>
#include <cmath>
#include <limits>
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

void GaussJ::swapRows(Matrix& matrix, int idx_1, int idx_2)
{
    int n = matrix.GetNumCols();
    
    double temp;
    for(int j = 0; j < n; ++j)
    {
        temp = matrix(idx_1, j);
        matrix(idx_1, j) = matrix(idx_2, j);
        matrix(idx_2, j) = temp;
    }
}

vector<double> GaussJ::gaussElimination()
{
    Matrix aug = augmentMatrix();
    int N = aug.GetNumRows();
    
    for(int col_itr = 0; col_itr < N; ++col_itr)
    {
        // Search for maximum element in the column
        double max_entry = aug(col_itr, col_itr);
        int max_row = col_itr;

        for(int row_itr = (col_itr+1); row_itr < N; ++row_itr)
        {
            if(fabs(aug(row_itr, col_itr)) >= max_entry + numeric_limits<double>::epsilon())
            {
                max_entry = fabs(aug(row_itr, col_itr));
                max_row = row_itr;
            }
        }
        
        // Swap current row with the maximum-entry row
        if(max_row != col_itr)
            swapRows(aug, col_itr, max_row);

        // Make all rows below the current row 0 in the current column
        for(int row_itr = (col_itr+1); row_itr < N; ++row_itr)
        {
            double multiplier = -1.0 * (aug(row_itr, col_itr)/aug(col_itr, col_itr));
            for(int col_itr2 = col_itr; col_itr2 < (N+1); ++col_itr2)
            {
                if(col_itr == col_itr2)
                    aug(row_itr, col_itr2) = 0;
                else
                    aug(row_itr, col_itr2) += multiplier * aug(col_itr, col_itr2);
            }
        }
    }

    // Solve the equations using the upper triangular matrix
    vector<double> solutions;
    solutions.resize(aug.GetNumRows(), 0.0);

    for(int i = (N-1); i >= 0; --i)
    {
        solutions[i] = (aug(i, N) / aug(i, i));
        for(int j = (i-1); j >= 0; --j)
            aug(j, N) -= (solutions[i] * aug(j, i));
    }
    return solutions;
}

#endif

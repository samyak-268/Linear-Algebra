#ifndef _GAUSSJ_H
#define _GAUSSJ_H

#include "matrix.h"

class GaussJ
{
    private:
        /*
         * The data members used in Gauss Elimination.
         * (1) Matrix A (Co-efficient matrix: N X N)
         *      Holds the co-efficients for the system of N linear equations in N unknowns.
         * (2) Matrix b (RHS vector: N X 1)
         *      Holds the RHS of the N equations.
         */
        
        Matrix A;
        Matrix b;
        
        /*
         * The helper functions used for Gauss elimination. All row numberings are 0-based.
         * (1) Matrix augmentMatrix()
         *      Returns the augmented matrix by concatenating b as a column with A
         * 
         * (2) void scaleRow(int row_idx, double multiplier)
         *      Multiplies every element in row_idx-th row with multiplier
         *
         * (3) void addRows(int idx_1, int idx_2)
         *      Adds row numbered idx_1 with row numbered idx_2 and saves the result in idx_1
         *
         * (4) void swapRows(int idx_1, int idx_2)
         *      Swaps the contents of the 2 rows numbered idx_1 and idx_2
         */
        
        Matrix augmentMatrix();
        void scaleRow(int row_idx, double multiplier);
        void addRows(int idx_1, int idx_2);
        void swapRows(int idx_1, int idx_2);


    public:
        GaussJ(const Matrix& _A, const Matrix& _b);
        void displayAugMatrix(const Matrix& aug);
};

#endif

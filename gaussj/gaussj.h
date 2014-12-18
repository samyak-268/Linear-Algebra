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
         * (2) void swapRows(Matrix& matrix, int idx_1, int idx_2)
         *      Swaps the contents of the 2 rows numbered idx_1 and idx_2 in matrix
         */
        
        Matrix augmentMatrix();
        void swapRows(Matrix& matrix, int idx_1, int idx_2);


    public:
        /*
         * (1) GaussJ(const Matrix& _A, const Matrix& _B)
         *      Constructor that initializes the co-efficent and RHS matrix with the
         *      values passed as arguments.
         *
         * (2) vector<double> gaussElimination()
         *      This method performs the actual Gauss elimination steps to solve the system
         *      of equations given by A and b. The solution is returned in the form of a 
         *      vector of doubles representing the values of x1, x2, x3, ..., xn.
         */

        GaussJ(const Matrix& _A, const Matrix& _b);
        vector<double> gaussElimination();
};

#endif

#ifndef _GAUSSJ_CPP
#define _GAUSSJ_CPP

#include <iostream>
#include "gaussj.h"
#define SWAP(a, b) {temp=(a); (a) = (b); (b) = temp;}
using namespace std;

// helper function for absolute value 
double fabs(double val) {
	if (val < 0.0) return -val;
	else val;
}

// Gauss-Jordan Elimination
void GaussJordan(Matrix& A, Matrix& b) {
/*
	Solution to linear equations of a matrix 
	Input : A[0..n-1][0..n-1] , b[0..n-1][0..m-1]
	Inverse of A and the solutions are stored in
	the b Matrix itself. 
*/
	int n = A.GetNumRows(), m = b.GetNumCols();
	vector<int> indxc, indxr, ipiv;
	int i, icol, irow, j, k, l, ll;
	double big, dum, pivinv, temp;

	indxr.resize(n);
	indxc.resize(n);
	ipiv.resize(n);

	for (i = 0; i < n; i++) {
		big = 0.0;
		for (j = 0; j < n; j++) {
			if (ipiv[j] != 1) {
				for (k = 0; k < n; k++) {
					if (ipiv[k] == 0) {
						if (fabs(A(j, k)) >= big) {
							big = fabs(A(j, k));
							irow = j;
							icol = k;
						}
					}
				}
			}
		}

		++(ipiv[icol]);
	/*
		After getting the pivot element in the previous
		step, we interchange rows, if needed. For the 
		ith pivot element indxr[i] and indxc[i] store 
		the row and column where it was stored originally.
		If indxr[i] != indxc[i] then there is an implied
		column interchange. 
	*/
		if (irow != icol) {
			for (l = 0; l < n; l++) SWAP(A(irow, l), A(icol, l)); 
			for (l = 0; l < m; l++) SWAP(b(irow, l), b(icol, l)); 
		}

		indxr[i] = irow;
		indxc[i] = icol;
		if (A(icol, icol) == 0.0) {
			cout << "Singular Matrix\n";
			return;
		}

		pivinv = 1.0/A(icol, icol);
		A(icol, icol) = 1.0;
		for (l = 0; l < n; l++) A(icol, l) *= pivinv;
		for (l = 0; l < m; l++) b(icol, l) *= pivinv;

		for (ll = 0; ll < n; ll++)
			if (ll != icol) {
				dum = A(ll, icol);
				A(ll, icol) = 0.0;
				for (l = 0; l < n; l++) A(ll, l) -= A(icol, l)*dum;
				for (l = 0; l < m; l++) b(ll, l) -= b(icol, l)*dum;
			}

	}

/*
	Unscramble the solution in view of column 
	interchanges. We do this by interchanging
	pairs of columns in the reverse order that
	the permuation was built.
*/

	for (l = n-1; l >= 0; l--) {
		if (indxr[l] != indxc[l]) {
			for (k = 0; k < n; k++) 
				SWAP (A(k, indxr[l]), A(k, indxc[l]));
		}
	}
}

#endif

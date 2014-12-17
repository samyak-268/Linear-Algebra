#ifndef _LUDEC_CPP
#define _LUDEC_CPP

#include <iostream>
#include "ludec.h"
#define SWAP(a, b) {temp=(a); (a) = (b); (b) = temp;}
using namespace std;

// helper function for absolute value 
double fabs(double val) {
	if (val < 0.0) return -val;
	else val;
}

int min(int x, int y) {
	if (x > y) return y;
	return x;
}

/*	
	Factorizes the matrix A into Lower Triangular
	Matrix L, Upper Triagular Matrix U and a 
	Permutation Matrix P which is required to 
	satisfy PA = LU
*/

void LUDecompose(Matrix& A, Matrix& L, Matrix& U, vector<int>& P) { 
	int n = A.GetNumRows();

	int i, j, irow, icol, k, l, ll, flag = 0;
	double piv, temp;

	for (i = 0; i < n; i++) 
		for (j = 0; j < n; j++) 
			U(i, j) = A(i, j);
	
	for (i = 0; i < n; i++) {
		L(i, i) = 1;
		P[i] = i;
	}

	for (j = 0; j < n; j++)	{ 
	/*
		The first non-zero pivot element is
		selected in the particular column
	*/ 
		for (k = j; k < n; k++)
			if (U(k, j) != 0.0) {
				piv = U(k, j);
				irow = k;
				icol = j;
				flag = 1;
				break;
			}
	/*
		After getting the required pivot the rows 
		are switched if needed and elements of L 
		matrix are switched accordingly
	*/
		if (flag == 0) {
			cout << "Singular Matrix";
			return;
		}

		if (irow != icol) {
			for (l = 0; l < n; l++) { 
				SWAP(A(irow, l), A(icol, l)); 
				SWAP(U(irow, l), U(icol, l));
			}

			ll = min(irow, icol);
			for (l = 0; l < ll; l++) SWAP(L(irow, l), L(icol, l));
		}

		SWAP(P[irow], P[icol]);
	/*
		Storing the permutation in the P matrix
		the row operations are done
	*/
		for (i = j+1; i < n; i++) {
			L(i, j) = U(i, j)/ U(j, j);

			for (ll = 0; ll < n; ll++) 
				U(i, ll) = U(i, ll) + (-L(i, j) * U(j, ll));
		}
	}
}

#endif

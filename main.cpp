#include "matrix.h"
#include "gaussj.h"
#include "ludec.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    double A_array[][3] = {{1, 0, 0}, {0, 1, 1}, {0, 0, 1}};
    double b_array[][1] = {{2}, {4}, {6}};
    
    vector<vector<double> > A_vector(3);
    vector<vector<double> > b_vector(3);
    
    for(int i = 0; i < 3; ++i)
        A_vector[i].assign(A_array[i], A_array[i] + 3);
    for(int i = 0; i < 3; ++i)
        b_vector[i].assign(b_array[i], b_array[i] + 1);
    
    Matrix A(4, 4, 0);
    A(0, 0) += 1;
    A(1, 0) += 2;
    A(2, 0) += -3;
    A(3, 0) += -1;
    A(0, 1) += 2;
    A(1, 1) += 4;
    A(2, 1) += -5;
    A(3, 1) += 2;
    A(0, 2) += -1;
    A(1, 2) += -2;
    A(2, 2) += 6;
    A(3, 2) += 8;
    A(0, 3) += 0;
    A(1, 3) += -1;
    A(2, 3) += 1;
    A(3, 3) += -2;
    
    cout << "A: \n";
    A.Display(); cout << "\n";

    Matrix L(4, 4, 0);
    Matrix U(4, 4, 0);
    vector<int> P(4, 0);

    LUDecompose(A, L, U, P);

    cout << "L: \n";
    L.Display(); cout << "\n";
    cout << "U: \n";
    U.Display(); cout << "\n";

    Matrix Perm(4, 4, 0);

    for (int i = 0; i < P.size(); i++)
        Perm(i, P[i]) = 1;
    cout << "P: \n";
    Perm.Display(); cout << "\n";

    Matrix A(A_vector);
    Matrix b(b_vector);
    
    GaussJ gaussj_obj(A, b);

    return 0;
}

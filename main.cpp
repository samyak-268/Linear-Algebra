#include "matrix.h"
#include "gaussj.h"
#include "ludec.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    /*
     * Example of new Matrix constructor at work: Matrix::Matrix(vector<vector<double> > _matrix)
     * Constructs a matrix object from the contents of a 2-D vector.
     */

    double X_array[][3] = {{1, 0, 0}, {0, 1, 1}, {0, 0, 1}};
    double y_array[][1] = {{2}, {4}, {6}};
    
    vector<vector<double> > X_vector(3);
    vector<vector<double> > y_vector(3);
    
    for(int i = 0; i < 3; ++i)
        X_vector[i].assign(X_array[i], X_array[i] + 3);
    for(int i = 0; i < 3; ++i)
        y_vector[i].assign(y_array[i], y_array[i] + 1);
    
    Matrix X(X_vector);
    Matrix y(y_vector);
    
    cout << "X: \n";
    X.Display();    cout << "\n";
    
    cout << "y: \n";
    y.Display();    cout << "\n";

    GaussJ gaussj_obj(X, y);
    Matrix aug = gaussj_obj.augmentMatrix();

    cout << "Augmented matrix: \n";
    aug.Display();
    cout << "\n";

    /*
     * Example demonstrating LU decomposition
     */
    
    
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

    return 0;
}

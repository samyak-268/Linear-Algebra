#include "matrix.h"
#include <iostream>
using namespace std;

int main()
{
    Matrix mat1(3, 3, 1);
    Matrix mat2(3, 3, 2);
    
    // Test for scalar matrix multiplication
    mat1.ScalarMultiply(5);
    mat1.Display(); cout << "\n";
    
    // Test for matrix addition and subtraction
    Matrix mat_sum = mat1 + mat2;
    Matrix mat_diff = mat1 - mat2;
    mat_sum.Display();  cout << "\n";
    mat_diff.Display(); cout << "\n";
    

    return 0;
}

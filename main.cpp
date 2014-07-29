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

    // Test for fetching row and column by their indices
    vector<int> second_row = mat1.GetRow(1);
    vector<int> first_col = mat1.GetCol(0);

    cout << "\nThe second row of the matrix: \n";
    for(int i = 0; i < second_row.size(); ++i)
        cout << second_row[i] << "  ";
    cout << "\n";

    cout << "\nThe first column of the matrix: \n";
    for(int i = 0; i < first_col.size(); ++i)
        cout << first_col[i] << "  ";
    cout << "\n";

    return 0;
}

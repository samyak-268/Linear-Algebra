#include "matrix.h"
#include "commandline.h"
#include "gaussj.h"
#include "ludec.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
    Commandline parser(argc, argv);
    if(!parser.doesCmdOptionExist("-input"))
    {
        cout << "Usage: ./LinearAlgebra [INPUT] where \n"
            "[INPUT]\n\tThe input file containing the 3 X 3 matrix elements.\n\n";
        return 1;
    }
    
    Matrix mat1(3, 3, 1);
    string input_file_path;
    input_file_path = parser.getCommandOption("-input");
    Matrix mat2(3, 3, input_file_path);
    
    // Test for scalar matrix multiplication
    mat1.ScalarMultiply(5);
    mat1.Display(); cout << "\n";
    
    // Test for matrix addition and subtraction
    Matrix mat_sum = mat1 + mat2;
    Matrix mat_diff = mat1 - mat2;
    mat_sum.Display();  cout << "\n";
    mat_diff.Display(); cout << "\n";

    // Test for setting and getting an element
    cout << mat_diff(2, 2) << "\n";
    mat_diff(2, 2) = 100;
    mat_diff.Display(); cout << "\n";

    // Test for fetching row and column by their indices
    vector<double> second_row = mat1.GetRow(1);
    vector<double> first_col = mat1.GetCol(0);

    cout << "\nThe second row of the matrix: \n";
    for(int i = 0; i < second_row.size(); ++i)
        cout << second_row[i] << "  ";
    cout << "\n";

    cout << "\nThe first column of the matrix: \n";
    for(int i = 0; i < first_col.size(); ++i)
        cout << first_col[i] << "  ";
    cout << "\n";

    // Test for matrix-vector multiplication functions
    int col_array[] = {2, -1, 1};
    vector<double> col_vec(col_array, (col_array + 3));
    vector<double> result_col_vec_mult = mat1.ColVectorMultiply(col_vec);
    cout << "\nResult of multiplying the matrix with a column vector: \n";
    for(int i = 0; i < result_col_vec_mult.size(); ++i)
        cout << result_col_vec_mult[i] << "  ";
    cout << "\n";

    int row_array[] = {2, 1, 0};
    vector<double> row_vec(row_array, (row_array + 3));
    vector<double> result_row_vec_mult = mat1.RowVectorMultiply(row_vec);
    cout << "\nResult of multiplying the row vector with a matrix: \n";
    for(int i = 0; i < result_row_vec_mult.size(); ++i)
        cout << result_row_vec_mult[i] << "  ";
    cout << "\n";

    // Test for matrox-matrix multiplication
    Matrix product_matrix = mat1.NaiveMultiply(mat2);
    product_matrix.Display();

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

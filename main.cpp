#include "matrix.h"
#include "commandline.h"
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

    // Test for matrix-vector multiplication functions
    int col_array[] = {2, -1, 1};
    vector<int> col_vec(col_array, (col_array + 3));
    vector<int> result_col_vec_mult = mat1.ColVectorMultiply(col_vec);
    cout << "\nResult of multiplying the matrix with a column vector: \n";
    for(int i = 0; i < result_col_vec_mult.size(); ++i)
        cout << result_col_vec_mult[i] << "  ";
    cout << "\n";

    int row_array[] = {2, 1, 0};
    vector<int> row_vec(row_array, (row_array + 3));
    vector<int> result_row_vec_mult = mat1.RowVectorMultiply(row_vec);
    cout << "\nResult of multiplying the row vector with a matrix: \n";
    for(int i = 0; i < result_row_vec_mult.size(); ++i)
        cout << result_row_vec_mult[i] << "  ";
    cout << "\n";

    // Test for matrox-matrix multiplication
    Matrix product_matrix = mat1.NaiveMultiply(mat2);
    product_matrix.Display();

    
    return 0;
}

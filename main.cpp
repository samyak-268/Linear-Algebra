#include "matrix.h"
#include "gaussj.h"
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
    
    Matrix A(A_vector);
    Matrix b(b_vector);
    
    GaussJ gaussj_obj(A, b);

    return 0;
}

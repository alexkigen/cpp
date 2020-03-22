//working with matrices in C++

#include <iostream>

using namespace std;

//define the dimensions of the matrix (preprocessor directives)

#define NROW 4
#define NCOL 3

typedef double MATRIX [NROW][NCOL];
typedef double VECTOR [NROW];

//function to print matrix

void printMatrix (MATRIX matrix_) {

    for (int i = 0; i < NROW; ++i) {
        
        cout << endl << " ";

        for (int j = 0; j < NCOL; ++j) {

            cout << matrix_[i][j] << " ";
        }
//        cout << ")";
    }
    cout << endl;
}

int main () {

    MATRIX matA;

    //first row of matrix
    matA[0][0] = 1;
    matA[0][1] = 2;
    matA[0][2] = 3;
    //second row
    matA[1][0] = 1;
    matA[1][1] = 2;
    matA[1][2] = 3;
    //third row
    matA[2][0] = 1;
    matA[2][1] = 2;
    matA[2][2] = 3;
    //fourth row
    matA[3][0] = 1;
    matA[3][1] = 2;
    matA[3][2] = 3;

//print(matA);
    printMatrix(matA);
}

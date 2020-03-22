//working with matrices in C++

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//define the dimensions of the matrix (preprocessor directives)

#define NROW 4
#define NCOL 4

#define NROWB 4
#define NCOLB 4

typedef double MATRIX [NROW][NCOL];
typedef double MATRIXB [NROWB][NCOLB];
typedef double VECTOR [NROW];

//function to print matrix

void printMatrix (MATRIX matrix_, int nrow, int ncol) {


    for (int i = 0; i < nrow; ++i) {
        
        cout << endl << " ";

        for (int j = 0; j < ncol; ++j) {

            cout << matrix_[i][j] << " ";
        }
//        cout << ")";
    }
    cout << endl;
}

//function to compute the determinant of a matrix

double determinant (MATRIXB matrix_, int nrow, int ncol) {
    
    double det = 0;
    MATRIXB innerMat;

    //vector to hold parts
    vector<double> results;
    results.assign(0, nrow);

    if (nrow == 2) {
                det = matrix_[0][0]*matrix_[1][1] - matrix_[0][1]*matrix_[1][0]; 
    } else {

       for (int x = 0; x < nrow; x++) {
           
           int innerRow = 0;

            for (int row = 1; row < nrow; row++) {

                int innerCol = 0;

                    for (int col = 0; col < ncol; col++) {

                        if (col == x)
                            continue;

                            innerMat[innerRow][innerCol] = matrix_[row][col];
                            innerCol++;
                    }
                    innerRow++;
                    }
            det += pow(-1, x) * matrix_[0][x] * determinant (innerMat, nrow - 1, ncol - 1);
            
    }
    }
    
    return det;
}

//function to multiply two matrices; can be used consecutively for more matrices


int main () {

    MATRIX matA;

    //first row of matrix
    matA[0][0] = 5;
    matA[0][1] = 7;
    matA[0][2] = 3;
    matA[0][3] = 6;
    //second row
    matA[1][0] = 2;
    matA[1][1] = 5;
    matA[1][2] = 9;
    matA[1][3] = 1;
    //third row
    matA[2][0] = 3;
    matA[2][1] = 6;
    matA[2][2] = 9;
    matA[2][3] = 1;
    //fourth row
    matA[3][0] = 2;
    matA[3][1] = 4;
    matA[3][2] = 6;
    matA[3][3] = 8;

//print(matA);

    MATRIX matB;

    matB[0][0] = 3;
    matB[0][1] = 8;
    matB[1][0] = 4;
    matB[1][1] = 6;

    cout << endl;
    cout << "Matrix B: " << endl;
    printMatrix(matB, 2, 2);
    cout << "The determinant of matrix B is : " << determinant(matB, 2, 2) << endl;

    cout << "Matrix A: " << endl;
    printMatrix(matA, 4, 4);
    cout << "The determinant of matrix A is: " << determinant(matA, 4, 4) << endl;

    //user supplied matrix
    int nrows = 4;
    int ncols = 4;

    bool userInput = false;

    cout << "Do you want to define own matrix?: " << endl;
    cout <<"[0 for no, 1 for yes]" << endl;
    cin >> userInput;

    while (userInput == true) {
    
    cout << "Enter number of rows: " << endl;
    cin >> nrows;
    cout << "Enter number of columns: " << endl;
    cin >> ncols;

    #define NROW nrow
    #define NCOL ncol
    #define NROWB nrow
    #define NCOLB ncol

    MATRIXB matrix;

    cout << "Enter the values of the matrix [hit enter after every value]: ";
    
    for (int i = 0; i < nrows; ++i) {
        for (int j = 0; j < ncols; ++j) {
            cin >> matrix[i][j];
        }
    }

    printMatrix(matrix, nrows, ncols);
    cout << "The determinant of the matrix is: " << determinant(matrix, nrows, ncols) << endl;

    userInput = false;
    } //end of while statement
}
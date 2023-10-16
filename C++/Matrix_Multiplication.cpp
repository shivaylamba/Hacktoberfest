#include <iostream>
using namespace std;

int main() {
    int rows1, cols1, rows2, cols2;

    // Input the dimensions of the first matrix
    cout << "Enter the number of rows for Matrix 1: ";
    cin >> rows1;
    cout << "Enter the number of columns for Matrix 1: ";
    cin >> cols1;

    // Input the dimensions of the second matrix
    cout << "Enter the number of rows for Matrix 2: ";
    cin >> rows2;
    cout << "Enter the number of columns for Matrix 2: ";
    cin >> cols2;

    // Check if multiplication is possible
    if (cols1 != rows2) {
        cout << "Matrix multiplication is not possible. Number of columns in Matrix 1 must be equal to the number of rows in Matrix 2." << endl;
        return 1;
    }

    // Initialize the matrices
    int matrix1[rows1][cols1];
    int matrix2[rows2][cols2];

    // Input the elements of the first matrix
    cout << "Enter the elements of Matrix 1:" << endl;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            cin >> matrix1[i][j];
        }
    }

    // Input the elements of the second matrix
    cout << "Enter the elements of Matrix 2:" << endl;
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            cin >> matrix2[i][j];
        }
    }

    // Initialize the result matrix with zeros
    int result[rows1][cols2] = {0};

    // Perform matrix multiplication
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Display the result
    cout << "Resultant Matrix:" << endl;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
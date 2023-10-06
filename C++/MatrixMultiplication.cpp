#include <iostream>
using namespace std;
int main()
{
    int col_a=0, col_b=0, row_a=0, row_b=0;

    cout << "Enter Columns Of Matrix A: ";
    cin >> col_a;

    cout << "Enter Rows Of Matrix A: ";
    cin >> row_a;

    cout << "Enter Columns Of Matrix B: ";
    cin >> col_b;

    cout << "Enter Rows Of Matrix B: ";
    cin >> row_b;

    int a[row_a][col_a], b[row_b][col_b], sum[100][100], diff[100][100], temp_var, multiply[row_a][col_b];

    // Taking Input Of Matrix A
    cout << "A:\n";
    for (int i = 0; i < row_a; i++)
        for (int j = 0; j < col_a; j++)
            cin >> a[i][j];

    // Taking Input Of Matrix B
    cout << "B:\n";
    for (int i = 0; i < row_b; i++)
        for (int j = 0; j < col_b; j++)
            cin >> b[i][j];

    cout << "Product of the matrices:\n";

    for (int i = 0; i < row_a; i++)
    {
        for (int j = 0; j < col_b; j++)
        {
            temp_var = 0;
            for (int k = 0; k < row_b; k++)
            {
                temp_var = temp_var + a[i][k] * b[k][j];
            }
            multiply[i][j] = temp_var;
        }
    }

    for (int i = 0; i < row_a; i++)
    {
        for (int j = 0; j < col_b; j++)
        {
            cout <<multiply[i][j]<<" ";
        }
        cout << "\n";
    }
}
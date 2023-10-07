#include <iostream>
#include <vector>
using namespace std;

void print2D(vector<vector<int>> arr, int mrow, int ncol)
{
    cout << "The 2D matrix is : " << endl;
    for (int row = 0; row < mrow; row++)
    {
        for (int col = 0; col < ncol; col++)
            cout << arr[row][col] << " ";
        cout << endl;
    }
    cout << endl;
}

void print1D(vector<int> vec)
{
    cout << "The spiral form is : " << endl;
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
}

vector<int> spiral(vector<vector<int>> matrix)
{
    vector<int> result;

    int row = matrix.size();
    int col = matrix[0].size();

    int count = 0;
    int total = row * col;

    // initializing the indexes
    int sRow = 0, sCol = 0, eRow = row - 1, eCol = col - 1;

    while (count < total)
    {
        // printing the starting row
        for (int index = sCol; count < total && index <= eCol; index++)
        {
            result.push_back(matrix[sRow][index]);
            count++;
        }
        sRow++;

        // printing the ending column
        for (int index = sRow; count < total && index <= eRow; index++)
        {
            result.push_back(matrix[index][eCol]);
            count++;
        }
        eCol--;

        // printing the ending row
        for (int index = eCol; count < total && index >= sCol; index--)
        {
            result.push_back(matrix[eRow][index]);
            count++;
        }
        eRow--;

        // printing the starting column
        for (int index = eRow; count < total && index >= sRow; index--)
        {
            result.push_back(matrix[index][sCol]);
            count++;
        }
        sCol++;
    }
    return result;
}

int main()
{
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    print2D(matrix, 3, 3);
    print1D(spiral(matrix));
    return 0;
}
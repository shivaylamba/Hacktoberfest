#include<iostream>
using namespace std;

//Function to read the matrix
void ReadMatrix(int matrix[][10],int totalRows,int totalCols)
{
    for(int row=0;row<totalRows;row++)
    {
        for(int col=0;col<totalCols;col++)
        {
            cin>>matrix[row][col];
        }
    }
}

//Function to print the Wave form
void WavePrint(int matrix[][10],int totalRows,int totalCols)
{
    //Iteration over columns
    for(int col=0;col<totalCols;col++)
    {
        if(col&1)
        {
            //For odd columns
            for(int row=totalRows-1;row>=0;row--)
            {
                cout<<matrix[row][col]<<" ";
            }
        }
        else{
            //For even columns
            for(int row=0;row<totalRows;row++)
            {
                cout<<matrix[row][col]<<" ";
            }
        }
    }
}
int main()
{
    int totalRows,totalCols,matrix[10][10];

    cout<<"Enter the number of rows and columns:\n";
    cin>>totalRows>>totalCols;

    cout<<"Enter values of matrix \n";
    ReadMatrix(matrix,totalRows,totalCols);

    cout<<"The Wave form of the above matrix is\n";
    WavePrint(matrix,totalRows,totalCols);

    return 0;
}

/*Sample Input
No of Rows: 4
No of Cols: 4
Matrix:
10 11 12 13
14 15 16 17
18 19 20 21
22 23 24 25
Output:
10 14 18 22 23 19 15 11 12 16 20 24 25 21 17 13*/

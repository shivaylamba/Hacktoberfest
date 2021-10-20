//Accessing elements in Three-Dimensional Arrays: Accessing elements in Three-Dimensional Arrays is also similar to that of Two-Dimensional Arrays. 
 // The difference is we have to use three loops instead of two loops for one additional dimension in Three-dimensional Arrays.
#include<iostream>
using namespace std;
  
int main()
{
    // initializing the 3-dimensional array
    int x[2][3][2] =
    {
        { {0,1}, {2,3}, {4,5} },
        { {6,7}, {8,9}, {10,11} }
    };
  
    // output each element's value
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 2; ++k)
            {
                cout << "Element at x[" << i << "][" << j
                     << "][" << k << "] = " << x[i][j][k]
                     << endl;
            }
        }
    }
    return 0;
}

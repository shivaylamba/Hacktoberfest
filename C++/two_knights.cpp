/*
Author : Aditya Choubey

Problem Statement :
This program counts for k=1,2,…,n the number of ways two knights can be placed on a k×k chessboard so that they do not attack each other.
*/
#include <iostream>

using namespace std;

int main()
{
    unsigned long long int n;
    cin >> n;

    for(unsigned long long int i = 1; i <= n; i++)
    {
        //FIND NUMBER OF WAYS TWO KNIGHTS CAN BE PLACED ON i X i CHESSBOARD WITHOUT ATTACKING EACH OTHER
        //KNIGHTS ATTACK EACH OTHER WHEN THEY FORM 2 X 3 GRID OR 3 X 2 GRID.
        //SO COUNT NUMBER OF 2 X 3 GRIDS AND 3 X 2 GRIDS AND REMOVE FROM TOTAL GRIDS.

        unsigned long long int ans = (i*i)*(i*i-1)/2 - (4*(i-1)*(i-2));
        cout << ans << endl;
    }
    return 0;
}
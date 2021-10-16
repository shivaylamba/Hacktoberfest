#include <bits/stdc++.h>
using namespace std;

int jos (int n, int k)
{
    if(n == 1)
        return 0;
    else return (jos((n-1), k)+k) % n;

}

int main ()
{
    int noOfPersons , interval;
    cout<<"Enter the no. of persons in the circle : ";
    cin>>noOfPersons;
    cout<<"Enter the interval of kill : ";
    cin>>interval;
    int j = jos(noOfPersons, interval);
    cout<<"--------------------------------------------";
    cout<<"\nAfter the Game, person no. "<<j<<" is left.";
    return 0;
}

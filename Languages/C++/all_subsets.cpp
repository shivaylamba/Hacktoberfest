#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ulli;
typedef long long int lli;

void printSubsets(char* arr, int n/*max 64*/)
{
    //print subsets of given array of size n
    //
    //to do so, make a n long bit
    //sequentially make it 0 to (2^n)-1
    //print only those elements whose bit is set
    ulli mask = 1;
    ulli max = pow(2,n)-1;
    for(ulli var=0; var<=max; ++var)
    {
        ulli temp=var;
        int i=0;
        while(temp)
        {
            if(temp&mask==1)
            {
                cout<<arr[i]<<' ';
            }
            temp>>=1;
            ++i;
        }
        cout<<endl;
    }
    return;
}

int main()
{
    //PRINT ALL SUBSETS
    char arr[65];
    cin>>arr;
    printSubsets(arr, strlen(arr)); 
    return 0;
}




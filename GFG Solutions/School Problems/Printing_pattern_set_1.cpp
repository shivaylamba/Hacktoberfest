/*
You are given a number N. You need to print the pattern for the given value of N.

For N = 2 the pattern will be 
2 2 1 1
2 1

For N = 3 the pattern will be 
3 3 3 2 2 2 1 1 1
3 3 2 2 1 1
3 2 1

Note: Instead of printing a new line print a "$" without quotes. After printing the total output, end of the line is expected.
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
void printPat(int n);

void printPat(int n ){
    for(int i=n;i>=1;i--){
        int elemet = n;
        for(int j=n;j>=1;j--){
           for(int k=1;k<=i;k++){
            cout<<elemet<<" ";
           }
           elemet--;
             }
             cout<<endl;
            }
    }
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
    printPat(n);
    cout<<endl;
	}
}
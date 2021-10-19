#include<iostream>
using namespace std;
int main()
{
int n, i , j;
cout << "Enter number of rows: ";
cin >> n;
for(i = 1; i <= n; i++)
{
for(j = 1; j <= i; j++)
{
cout << "*";
}
cout<<"\n";
}
for(i = n; i >= 1; i--)
{
for(j = 1; j <= i; j++)
{
cout << "*" ;
}
// ending line after each row
cout<<"\n";
}
return 0;
}
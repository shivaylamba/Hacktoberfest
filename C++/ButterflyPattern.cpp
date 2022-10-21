#include<iostream>
using namespace std;
int main()
{
  int r, i, j;
  cin>>r;
  
  for(i=1;i<=r;i++)
  {
    for(j=1;j<=i;j++)
    cout<<"*";
    for(j=1;j<=2*(r-i);j++)
    cout<<" ";
    for(j=1;j<=i;j++)
    cout<<"*";
    cout<<"\n";
  }
    for(i=r;i>=1;i--)
  {
    for(j=1;j<=i;j++)
    cout<<"*";
    for(j=1;j<=2*(r-i);j++)
    cout<<" ";
    for(j=1;j<=i;j++)
    cout<<"*";
    cout<<"\n";
  }
  return 0;
}

#include<iostream>
using namespace std;
int main()
{
int n;
int sum=0;
printf("Enter n ");
cin>>n;
int A[n][n],B[n][n],C[n][n];
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
cout<<"Enter A[i][j] ";
cin>>A[i][j];
}
}

for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
cout<<"Enter B[i][j] ";
cin>>B[i][j];
}
}

for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
sum=0;
for(int k=i;k<n;k++)
{
sum=sum+(A[i][k]*B[k][j]);
}
C[i][j]=sum;
}
}

for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
cout<<C[i][j]<<" ";
}
cout<<"\n";
}

return 0;
}

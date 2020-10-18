#include<bits/stdc++.h>
#include <iostream>
#define mod 1000000007
using namespace std;
int findIndex(int a[],int n,int x, int p)
{
 int min=100000000,minp=0;
 for(int i=0;i<n;i++)
 if(a[i]==x)
 {
  if(abs(p-i)<min)
  {
   min=abs(p-i);
   minp=i;
  }
 }
 return minp;
}

void subMain() {
 int N,M,p,k;
 cin >>N>>M>>p>>k;
 int a[N];
 for(int i=0;i<N;i++)
 cin>>a[i];
 sort(a,a+N);
 int index =findIndex(a,N,M,p);
 int count=0;
 if(a[index] !=M)
 {
  a[k-1]=M;
 sort(a,a+N);
 count++;
 }
if(a[p-1] == M)
{
 cout<<0+count;
 return;
}
if(p<k && a[p-1] < M)
{
 cout <<-1;
 return;
}
if(p>k && a[p-1] > M)
{
 cout<<-1;
 return;
}
index = findIndex(a,N,M,p)+1;
cout<<abs(p-index)+count;
}
int main()
{
 int t;
 cin >> t;
 while(t--)
 {
  subMain();
  cout<<"\n";
 }
	return 0;
}

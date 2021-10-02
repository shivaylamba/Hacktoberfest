#include <iostream>
#include <cmath>
using namespace std;
void TOH(int n,int A,int B,int C)
{
 if(n>0)
 {
 TOH(n-1,A,C,B);
 printf("(%d,%d)\n",A,C);
 TOH(n-1,B,A,C);
 }
}
int main()
{
   int n;
   cout<<"How many Discs? : ";
   cin>>n; 
   TOH(n,1,2,3);
   cout<<"number of moves is "<<pow(2,n)-1<<endl;
   return 0;
}

#include<bits/stdc++.h>
using namespace std;
int toh(int n,string source,string mid,string des)
{
      int step=0;
      //Base Case
      if(n==1)
       {
        step++;
        cout<<"Move "<<n<<"th disc from "<<source<<" to "<<des<<"\n";
       }
       //Recursive Case
       else
        {
        step+=toh(n-1,source,des,mid);//counting steps
        cout<<"Move "<<n<<"th disc from "<<source<<" to "<<des<<"\n";
        step++;
        step+=toh(n-1,mid,source,des);
}
return step;
}

int main()
{
    int n,step=0;
    cout<<"Enter the no of disks: ";
    cin>>n;
    int res=toh(n,"T1","T2","T3");
    cout<<"The number of moves made to shift from all disks from T1 to T3 are "<<res;
    return 0;
}

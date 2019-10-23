#include <iostream>
#include<algorithm>
using namespace std;
bool possible(long arr[],long n,long c,long d){
    long cow=1;
    long t=0;
    for(long i=1;i<n;i++)
    {
        if(arr[i]-arr[t]>=d){
            cow++;
            t=i;
        }
    }
    if(cow>=c){
        return true;
    }
    else return false;
}
int main() {
   int t;
   cin>>t;
   while(t>0){
       long n,c;
       cin>>n;
       cin>>c;
       long arr[n];
       for(long i=0;i<n;i++){
           cin>>arr[i];
       }
       sort(arr,arr+n);
       long start=0;
       long end=arr[n-1]-arr[0];
       long ans=0;
       while(start<=end){

           long mid=(start+end)/2;
           if(possible(arr,n,c,mid)){
               start=mid+1;
               ans=mid;
           }
           else{
               end=mid-1;
           }
       }
       cout<<ans<<endl;
       t--;
   }


}

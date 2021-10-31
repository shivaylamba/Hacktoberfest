#include <iostream>
using namespace std;

int main() {
int start=0,end,mid,n,i,item;
cout<<"enter n"<<endl;
cin>>n;
int arr[n];
cout<<"enter data"<<endl;
for(i=0;i<n;i++){
    cin>>arr[i];
}
cout<<"enter item"<<endl;
cin>>item;
start=0;
end=n-1;
mid=(start+end)/2;
while(start<=end && arr[mid]!=item){
    if(item<arr[mid]){
        start=0;
        end=mid-1;
    }else{
        start=mid+1;
        end=n-1;
    }
    mid=(start+end)/2;
}
if(arr[mid]==item)cout<<item<<" found in position "<<mid+1;
else cout<<item<<" not found";
    return 0;
}

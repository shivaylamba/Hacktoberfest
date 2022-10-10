#include <iostream>
#include <cstring>
using namespace std;
 
int main(){
    int n=0;
    int height[101];
    int a=0, b=0, l=0, s=0;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> height[i];
    }
    a=height[0];
    for(int i=0;i<n;i++){
        if (a<height[i]){
            a=height[i];
            l=i;
        }        
    }
    b=height[0];
    for(int i=0;i<n;i++){
        if (height[i]<=b){
            b=height[i];
            s=i;
        }        
    }
    
    int t= l+(n-1)-s;          //total
    if (l>s){
        cout << t-1;
    }
    else cout << t;
    
return 0;}

//Problem link=> https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

#include <bits/stdc++.h>
using namespace std;
int trappingWater(int arr[], int n){
        
        int prefixMax[n];
        int suffixMax[n];
        prefixMax[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            prefixMax[i]=max(arr[i],prefixMax[i-1]);
        }
        suffixMax[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffixMax[i]=max(arr[i],suffixMax[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int x=min(prefixMax[i],suffixMax[i])-arr[i];
            ans+=x;
        }
        return ans;
    }
int main() {
      int n;
        
    
        cin >> n;
        
        int a[n];
        
      
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
   
       
        cout << trappingWater(a, n) << endl;
}

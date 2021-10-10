#include <bits/stdc++.h>
using namespace std;

int Search(vector<int>& arr, int target)
{
    int low = 0;
    int high = arr.size()-1;

    while (low<=high) {

        int mid = (low+high)/2;

        if(arr[mid]==target) return mid;

        if(arr[mid]>=arr[low]){ 

            if(arr[mid]>=target and arr[low]<=target)
                high = mid - 1;
            else low = mid + 1;  

        }  
        else{

            if(arr[mid]<=target and arr[high]>=target) 
                low = mid + 1;
            else high = mid - 1;
            
        }    
        
    }
    return -1;
}

int main()
{
    vector<int> arr = {4,5,6,7,0,1,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << " Search in rotated array " << Search(arr, 0);
    return 0;
}

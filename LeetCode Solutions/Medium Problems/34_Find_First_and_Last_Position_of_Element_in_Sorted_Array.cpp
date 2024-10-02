/*
First and Last Position of an Element In Sorted Array
Given an array of integers nums sorted in non-decreasing order, 
find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.
Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
Constraints:
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109
*/
#include<bits/stdc++.h>
using namespace std;
//  Time Complixity O(log(N))
//  Space Complixity O(N)
int fistOccurence(vector<int>& arr,int n,int key){
     int st=0 , en = n-1;
    int mid =st + (en - st)/2; // optimized solution for large array
    int ans =-1;
   while (st<=en){
    if(arr[mid] == key){
        ans =mid ;
        en =mid-1; 
    }
    else if(arr[mid]<key){
        st = mid+1;
    }
    else if(arr[mid] > key){
        en = mid - 1 ;
    }
     mid =st + (en - st)/2;
   }
   return ans;
}
int lastOccurence(vector<int>& arr,int n,int key){
     int st=0 , en = n-1;
    int mid =st + (en - st)/2; // optimized solution for large array
    int ans =-1;
   while (st<=en){
    if(arr[mid] == key){
        ans =mid ;
        st =mid+1; 
    }
    else if(arr[mid]<key){
        st = mid+1;
    }
    else if(arr[mid] > key){
        en = mid - 1 ;
    }
     mid =st + (en - st)/2;
   }
   return ans;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here
    pair<int,int> p;
    p.first = fistOccurence(arr,n,k);
    p.second = lastOccurence(arr,n,k);
    return p;
}
class Solution {
public:
    int lowerrange(vector<int>& nums, int target){
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                ans=mid;
                high=mid-1;
            } else if(nums[mid]<target)
                      low=mid+1;
                else high=mid-1;     
        }
        return ans;
    }
    int higherrange(vector<int>& nums, int target){
         int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target){
                ans=mid;
                low=mid+1;
            } else if(nums[mid]<target)
                      low=mid+1;
                else high=mid-1;     
        } 
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {lowerrange(nums,target),higherrange(nums,target)};
        
    }
};
int main(){
    int t;
    cin>>t;
    int n;
    while (t--)
    {
        /* code */
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        for(int x:arr){
            cout<<x<<" ";
        }
        int key ;
        cin>>key;
        cout<<fistOccurence(arr,n,key)<<endl;
        cout<<lastOccurence(arr,n,key)<<endl;
       pair<int , int> res = firstAndLastPosition(arr,n,key);
       cout<< res.first <<" : "<< res.second <<endl;
    }
    
}
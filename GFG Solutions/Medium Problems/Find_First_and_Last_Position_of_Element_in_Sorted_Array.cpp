/*
First and Last Position of an Element In Sorted Array
Given a sorted array arr containing n elements with possibly some duplicate, the task is to find the first and last occurrences of an element x in the given array.
Note: If the number x is not found in the array then return both the indices as -1.
Example 1:
Input:
n=9, x=5
arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
Output:  
2 5
Explanation: 
First occurrence of 5 is at index 2 and last occurrence of 5 is at index 5. 
Example 2:

Input:
n=9, x=7
arr[] = { 1, 3, 5, 5, 5, 5, 7, 123, 125 }
Output:  
6 6
Explanation: 
First and last occurrence of 7 is at index 6.
Your Task:
Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function find() that takes array arr, integer n and integer x as parameters and returns the required answer.

Expected Time Complexity: O(logN)
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 106
1 ≤ arr[i],x ≤ 109
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
/*
Count Smaller elements
Given an array arr containing non-negative integers. Count and return an array ans where ans[i] denotes the number of smaller elements on right side of arr[i].

Examples:

Input: arr[] = [12, 1, 2, 3, 0, 11, 4]
Output: [6, 1, 1, 1, 0, 1, 0]
Explanation: There are 6 smaller elements right after 12. There is 1 smaller element right after 1. And so on.
Input: arr[] = [1, 2, 3, 4, 5]
Output: [0, 0, 0, 0, 0]
Explanation: There are 0 smaller elements right after 1. There are 0 smaller elements right after 2. And so on.
Expected Time Complexity: O(n*logn)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i]  ≤ 108
*/
// User function Template for C++
//  User function template for C++

class Solution {
  public:
  int bs(vector<int>&arr,int x){
      int i = 0,index = -1  , j = arr.size()-1;
      int mid ;
     while(i<=j){
         mid = i+(j-i)/2;
         if(arr[mid]==x){  index = mid ; j = mid-1; }
         else if(arr[mid]<x) i =mid+1;
         else j = mid-1;
     }
     return index;
  }
    vector<int> constructLowerArray(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int> ans , vec(arr);
        sort(vec.begin(),vec.end());
        for(int i = 0  ; i<n;i++){
            int idx = bs(vec,arr[i]);
                ans.push_back(idx);
                vec.erase(vec.begin()+idx);
        }
        return ans;
    }
};
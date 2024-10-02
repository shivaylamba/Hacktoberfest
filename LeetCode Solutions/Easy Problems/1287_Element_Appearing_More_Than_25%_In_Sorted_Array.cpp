/*
Given an integer array sorted in non-decreasing order, there is exactly one 
integer in the array that occurs more than 25% of the time, return that integer.

Example 1:

Input: arr = [1,2,2,6,6,6,6,7,10]
Output: 6
Example 2:

Input: arr = [1,1]
Output: 1
 
Constraints:

1 <= arr.length <= 104
0 <= arr[i] <= 105
*/
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int maxa = -999;
        int n = arr.size()/4;
        for(int i = 0 ; i <arr.size();i++){
            maxa = max(maxa,arr[i]);
        }
        vector<int> ans(maxa+1,0);
        for(int i = 0 ; i < arr.size();i++){
            ans[arr[i]]++;
        }
        for(int i = 0 ; i<ans.size();i++){
            if(ans[i]>n){
                return i;
            }
        }
return -1;
    }
};
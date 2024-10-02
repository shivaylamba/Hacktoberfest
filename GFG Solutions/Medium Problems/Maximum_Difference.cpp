/*
Maximum Difference
Given an integer array arr of integers, the task is to find the maximum absolute difference between the nearest left smaller element and the nearest right smaller element of every element in array arr. If for any component of the arr, the nearest smaller element doesn't exist then consider it as 0.

Examples :

Input: arr = [2, 1, 8]
Output: 1
Explanation: left smaller array ls = [0, 0, 1], right smaller array rs = [1, 0, 0]. Maximum Diff of abs(ls[i] - rs[i]) = 1
Input: arr = [2, 4, 8, 7, 7, 9, 3]
Output: 4
Explanation: left smaller array ls = [0, 2, 4, 4, 4, 7, 2], right smaller rs = [0, 3, 7, 3, 3, 3, 0]. Maximum Diff of abs(ls[i] - rs[i]) = abs(7 - 3) = 4
Expected Time Complexity: O(n)
Expected Space Complexity: O(n)

Constraints:
1 <= arr.size() <= 106
1<= arr[i] <=109
*/
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        vector<int> ls(arr.size(),0) , rs(arr.size(),0);
        stack<int> st;
        int n  = arr.size();
            for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ls[i] = st.top();
            }
            st.push(arr[i]);
        }
        while(!st.empty()) st.pop();
        for (int i = n-1; i >=0; i--) {
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                rs[i] = st.top();
            }
            st.push(arr[i]);
        }
        int diff= INT_MIN;
        for(int i = 0 ; i<n;i++) diff = max(diff,abs(ls[i]-rs[i]));
        return diff;
    }
};
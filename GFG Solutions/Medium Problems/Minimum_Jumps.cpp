/*
Minimum Jumps
Given an array arr[] of non-negative integers. Each array element represents the maximum length of the jumps that can be made forward from that element. This means if arr[i] = x, then we can jump any distance y such that y ≤ x.
Find the minimum number of jumps to reach the end of the array starting from the first element. If an element is 0, then you cannot move through that element.
Note:  Return -1 if you can't reach the end of the array.

Examples : 

Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3 
Explanation:First jump from 1st element to 2nd element with value 3. From here we jump to 5th element with value 9, and from here we will jump to the last. 
Input: arr = {1, 4, 3, 2, 6, 7}
Output: 2 
Explanation: First we jump from the 1st to 2nd element and then jump to the last element.
Input: arr = {0, 10, 20}
Output: -1
Explanation: We cannot go anywhere from the 1st element.
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraints:
0 ≤ arr[i] ≤ 105
2 ≤ arr.size() ≤ 106
*/

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // Your code here
          int n = arr.size();
       int far = 0 , curr = 0 , jump = 0;
       for(int i=0;i<n-1;i++){        
           far = max(far,arr[i]+i);
           if(i == curr){
               curr = far;
               jump++;
           }
       }
       if(curr>= n-1){
           return jump;
       }
       return -1;
    }
};
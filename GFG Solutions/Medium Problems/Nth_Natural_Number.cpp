/*
Nth Natural Number
Given a positive integer n. You have to find nth natural number after removing all the numbers containing the digit 9.
Examples :
Input: n = 8
Output: 8
Explanation: After removing natural numbers which contains digit 9, first 8 numbers are 1,2,3,4,5,6,7,8 and 8th number is 8.
Input: n = 9
Output: 10
Explanation: After removing natural numbers which contains digit 9, first 9 numbers are 1,2,3,4,5,6,7,8,10 and 9th number is 10.
Expected Time Complexity: O(logn)
Expected Auxiliary Space: O(1)
Constraints:
1 ≤ n ≤ 109
*/

class Solution {
  public:
    long long findNth(long long n) {
        // code here.
          long long r,res=0;
        int i=0;
        while (n>0){
            res+=pow(10,i++)*(n%9);
            n/=9;
        }
        return res;
    }
};
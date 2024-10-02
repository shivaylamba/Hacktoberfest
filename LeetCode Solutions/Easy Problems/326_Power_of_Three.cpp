/*
Given an integer n, return true if it is a power of three. Otherwise, return false.
An integer n is a power of three, if there exists an integer x such that n == 3x.

Example 1:
Input: n = 27
Output: true
Explanation: 27 = 33

Example 2:
Input: n = 0
Output: false
Explanation: There is no x where 3x = 0.

Example 3:
Input: n = -1
Output: false
Explanation: There is no x where 3x = (-1).

Constraints:
-231 <= n <= 231 - 1
*/
          // Approach -1 //
class Solution {
public:
    bool isPowerOfThree(int n) {
         int i=0 , j= n;
         int mid = i+ (j-i)/2;
         while(i<=j){
             if(pow(3 ,mid) == n){
                 return 1;
             }
             else if(pow(3,mid) < n){
                 i =mid +1;
             }
             else{
                 j =mid -1;
             }
             mid = i+ (j-i)/2;
         }
         return 0;
    }
};
      //Approach -2 //
 class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0){
            return false;
        }
        else if(n==1){
            return true;
        }
        return n%3==0 && isPowerOfThree(n/3);  
    }
};     
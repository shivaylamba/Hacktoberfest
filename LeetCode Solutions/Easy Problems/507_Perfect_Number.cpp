/*
507. Perfect Number
A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. A divisor of an integer x is an integer that can divide x evenly.

Given an integer n, return true if n is a perfect number, otherwise return false.

 

Example 1:

Input: num = 28
Output: true
Explanation: 28 = 1 + 2 + 4 + 7 + 14
1, 2, 4, 7, and 14 are all divisors of 28.
Example 2:

Input: num = 7
Output: false
 

Constraints:

1 <= num <= 108
*/
class Solution {
public:
    bool checkPerfectNumber(int num) {
    //     int ans =0;
    //     for(int i=1;i<=num/2;i++){
    //         if(num%i==0){ans+=i;}
    //     }
    //     return (ans==num)?1:0;

     if(num==0 || num==1) return false;
        int countNum=0;
        for(int i=2;i<=sqrt(num);i++){
            if(num%i==0) {
                countNum+=i;
                countNum+=num/i;
            }
        }
        countNum+=1;
        if(countNum==num) return true;
        return false;
    }
};
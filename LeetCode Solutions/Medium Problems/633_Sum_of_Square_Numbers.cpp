/*
633. Sum of Square Numbers
Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

 

Example 1:

Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:

Input: c = 3
Output: false
 

Constraints:

0 <= c <= 231 - 1
*/
/*
    TWO POINTER APPROACH
Time Complexity O(sqrt(n))
Space Complexity O(1)
*/
#define ll long long
class Solution {
public:
    bool judgeSquareSum(int c) {
        ll i= 0  ,   j = sqrt(c);
        while(i<=j){
            long long int sum = i*i + j*j;
            if(sum==c) return 1;
            else if(sum<c) i++;
            else j--;
        }
        return 0;
    }
};
/*
    TWO POINTER APPROACH
Time Complexity O(sqrt(n))
Space Complexity O(1)
*/
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long long a = 0; a * a <= c; a++) {
            int b = sqrt(c - a * a);
            if (b * b + a * a == c) return true;
        }
        return false;
    }
};
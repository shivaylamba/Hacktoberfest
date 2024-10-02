/*
Armstrong Numbers
You are given a 3-digit number n, Find whether it is an Armstrong number or not.

An Armstrong number of three digits is a number such that the sum of the cubes of its digits is equal to the number itself. 371 is an Armstrong number since 33 + 73 + 13 = 371. 

Note: Return "true" if it is an Armstrong number else return "false".

Examples

Input: n = 153
Output: true
Explanation: 153 is an Armstrong number since 13 + 53 + 33 = 153. Hence answer is "true".
Input: n = 372
Output: false
Explanation: 372 is not an Armstrong number since 33 + 73 + 23 = 378. Hence answer is "false".
Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1) 

Constraints:
100 ≤ n <1000 
*/
//------------------------------------------------------------------------------------------//
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n) {
        // code here
        int a = n;
        return (( pow((a/100)%10,3) +
                 pow((a/10)%10,3) + 
                 pow((a)%10,3) ) == n )?"true":"false";
    }
};
//------------------------------------------------------------------------------------------//
class Solution {
  public:
    string armstrongNumber(int n) {
        // code here
        int a = n;
        int ans = 0;
        while(a){
            ans+= pow(a%10,3);
            a/=10;
        }
        return (ans==n)?"true":"false";
    }
};
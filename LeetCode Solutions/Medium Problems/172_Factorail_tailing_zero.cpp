/*
172. Factorial Trailing Zeroes
Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.
Example 1:
Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:
Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Example 3:
Input: n = 0
Output: 0
Constraints:
0 <= n <= 104
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
// long long fact(long long n ){
//     return (n==0 || n==1)? 1: n*fact(n-1);
// }
    // int trailingZeroes(int n) {
    //     return (fact(n)%10==0)? 1:0;
    // }
    //     int trailingZeroes(int n) {
    //     int counter = 0;
    //       if(fact(n)%10==0){
    //  while(n>0){
    //         counter++;
    //         n/=10;
    //         trailingZeroes(n);
    //     }
    //  }
    //  return counter;
    // }
           int trailingZeroes(int n) {
 int counter =0 ;
 while(n>0){
     counter +=n/5;
     n/=5;
 }
     return counter;
    }
};
int main(){
    Solution s;
    int t;
    int n;
    cin>>t;
    while (t--)
    {
        cin>>n;
        cout<<s.trailingZeroes(n)<<endl;
    }
    
}
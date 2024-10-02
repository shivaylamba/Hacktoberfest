/*
Padovan Sequence
Given a number n, find the nth number in the Padovan Sequence.
A Padovan Sequence is a sequence which is represented by the following recurrence relation
P(n) = P(n-2) + P(n-3)
P(0) = P(1) = P(2) = 1
Note: Since the output may be too large, compute the answer modulo 10^9+7.
Examples :
Input: n = 3
Output: 2
Explanation: We already know, P1 + P0 = P3 and P1 = 1 and P0 = 1
Input: n = 4
Output: 2
Explanation: We already know, P4  = P2 + P1 and P2 = 1 and P1 = 1
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)
Constraints:
1 <= n <= 106
*/
/*
        DP or RECURSION
    Time Complexity :O(n);
    Space Complexity :O(n);
*/
class Solution
{
    public:
    int padovanSequence(int n)
    {
       //code here
       const int d = 1e9+7;
       vector<int> vec = {1,1,1} ;
       if(n<vec.size()) return vec[n];
       for(int i=3;i<=n;i++){
           vec.push_back((vec[i-2]%d+vec[i-3]%d)%d);
       }
       return vec[n];
    }
    
};
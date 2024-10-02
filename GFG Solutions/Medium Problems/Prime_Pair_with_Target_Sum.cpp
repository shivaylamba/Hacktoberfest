/*
Prime Pair with Target Sum
Given a number n, find out if n can be expressed as a+b, where both a and b are prime numbers. If such a pair exists, return the values of a and b, otherwise return [-1,-1] as an array of size 2.
Note: If [a, b] is one solution with a <= b, and [c, d] is another solution with c <= d, and a < c then  [a, b] is considered as our answer.
Examples
Input: n = 10
Output: 3 7
Explanation: There are two possiblities 3, 7 & 5, 5 are both prime & their sum is 10, but we'll pick 3, 7 as 3 < 5.
Input: n = 3
Output: -1 -1
Explanation: There are no solutions to the number 3.
Expected Time Complexity: O(n*loglog(n))
Expected Auxiliary Space: O(n)
Constraints:
2 <= n <= 106
*/
/*
    MOST OPTIMIZED APPROACH (Sieve of Eratosthenes)
Time complexity: O(n*log(logn))
Auxiliary Space: O(n)
*/
class Solution {
  public:
    vector<int> getPrimes(int n) {
        // code here
         vector<bool> prime(n+1,true);
    prime[0] = prime[1]=false;
    for(int i=2;i<=n;i++){
        if(prime[i]){
            for(int j=2*i;j<=n;j+=i){
                prime[j]=0;
            }
        }
    }
    for(int i =  2 ; i <n;i++){
        if(prime[i] && prime[n-i]){
            return {i , n - i };
        }
    }
    return {-1,-1};

    }
};
//---------------------------------------------------------------------------------------------//
class Solution {
  public:
    vector<int> getPrimes(int n) {
        // code here
        map<int,int> map;
         vector<bool> prime(n+1,true);
    prime[0] = prime[1]=false;
    for(int i=2;i<=n;i++){
        if(prime[i]){
            map[i]++;
            for(int j=2*i;j<=n;j+=i){
                prime[j]=0;
            }
        }
    }
    for(int i =  2 ; i <n;i++){
        if(map[n-i] && prime[i]){
            return {i,n-i};
        }
    }
    return {-1,-1};

    }
};
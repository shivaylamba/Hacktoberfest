//Dynamic Programming solution of Longest common subsequence problem

#include<bits/stdc++.h>
using namespace std;

const int maximum = 1000;

int LCS_dp(string s1, string s2, int m, int n, int memo[][maximum]){

 if (memo[m][n] != -1 ){
   return memo[m][n];
   }
   
 if (m == 0 || n == 0){
   memo[m][n] = 0;
 }
 else{
   if(s1[m-1] == s2[n-1]){
     memo[m][n] = 1 + LCS_dp(s1, s2, m-1, n-1, memo);
   }
   else{
     memo[m][n] = max(LCS_dp(s1, s2, m-1, n, memo), LCS_dp(s1, s2, m, n-1, memo));
   }
 }
 return memo[m][n];
}

int main(){
  string s1, s2;
  int m, n ;
  cout << "Enter string 1:\n";
  cin >> s1;
  cout << "Enter string 2:\n";
  cin >> s2;
  m = s1.size();
  n = s2.size();
  int memo[m+1][maximum];
  memset(memo, -1, sizeof(memo));
  cout << "Length of LCS: " << LCS_dp(s1, s2, m, n, memo);
  return 0;
}
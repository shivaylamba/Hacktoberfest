/*
Coin Collector
Our dear Sultan is visiting a country where there are n different types of coin. He wants to collect
as many different types of coin as you can. Now if he wants to withdraw X amount of money from a
Bank, the Bank will give him this money using following algorithm.
withdraw(X){
if( X == 0) return;
Let Y be the highest valued coin that does not exceed X.
Give the customer Y valued coin.
withdraw(X-Y);
}
Now Sultan can withdraw any amount of money from the Bank. He should maximize the number
of different coins that he can collect in a single withdrawal.
Input
First line of the input contains T the number of test cases. Each of the test cases starts with n
(1 ≤ n ≤ 1000), the number of different types of coin. Next line contains n integers C1, C2, …, Cn the
value of each coin type. C1 < C2 < C3 < . . . < Cn < 1000000000. C1 equals to 1.
Output
For each test case output one line denoting the maximum number of coins that Sultan can collect in a
single withdrawal. He can withdraw infinite amount of money from the Bank.
Sample Input
2
6
1 2 4 8 16 32
6
1 3 6 8 15 20
Sample Output
6
4
*/

#include<vector>
#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
#include<cmath>
using namespace std;

//count coins
int coin_conut(vector<int> v){
  int sum = 0, count = 1;
  for(int i=1; i<(int)v.size(); i++){
    if(v[i]>sum+v[i-1]){
      count++;
      sum+=v[i-1];
    }
  }
  return count;
}

int main(void){
  int n, m;
  scanf("%d", &n);//test number
  for(int i=0; i<n; i++){
    scanf("%d", &m);//ccoin number
    vector<int> v(m,0);
    for(int j=0; j<m; j++){
      scanf("%d", &v[j]);//coins values
    }
    printf("%d\n", coin_conut(v));//result
  }
}

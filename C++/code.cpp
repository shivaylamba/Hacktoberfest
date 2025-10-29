
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

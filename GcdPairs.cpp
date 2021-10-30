#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
  if(b == 0)
    return a;
  return gcd(b, a % b);
}

int main(){
  vector<int> arr;
  string input;
  getline(cin, input);
  istringstream is(input);
  int num;
  while(is >> num) arr.push_back(num);
  int n = arr.size();
  int count = 0;
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++ ){
      if(gcd(arr[j], arr[i]) == 1)
        count++;
    }
  }
  cout << count;
  return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  while(t--){
    int n , m;
    cin >> n >> m;
    getchar();
    string str1, str2, str3;
    getline(cin, str1);
    getline(cin, str2);
    int k = abs(str2[0] - str1[0]);
    getline(cin, str3);
    int length = str3.size();
    for(int i = 0;i<length;i++){
      str3[i] = 'A' + (str3[i]-'A'-k)%26;
    }
    cout << str3 << endl;
  }
  return 0;
}

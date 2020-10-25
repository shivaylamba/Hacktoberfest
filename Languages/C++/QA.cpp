#include<bits/stdc++.h>
using namespace std;
int main(){
  int h1,m1;
  char ch;
  int h2,m2;
  cin >> h1 >> ch >> m1;
  cin >> h2 >> ch >> m2;
  int time1 = h1*60 + m1;
  int time2 = h2*60 + m2;
  int avg = (time1+time2)/2;
  int h21 = floor(avg/60);
  int m21 = avg%60;
  printf("%.2d:%.2d\n",h21,m21);
  return 0;
}

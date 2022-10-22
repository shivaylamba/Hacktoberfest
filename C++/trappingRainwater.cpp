#include<bits/stdc++.h>

using namespace std;
int trap(vector < int > & arr) {
  int n = arr.size();
  int waterTrapped = 0;
  for (int i = 0; i < n; i++) {
    int j = i;
    int leftMax = 0, rightMax = 0;
    while (j >= 0) {
      leftMax = max(leftMax, arr[j]);
      j--;
    }
    j = i;
    while (j < n) {
      rightMax = max(rightMax, arr[j]);
      j++;
    }
    waterTrapped += min(leftMax, rightMax) - arr[i];
  }
  return waterTrapped;
}

int main() {
  vector < int > arr;
  arr = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << "The water that can be trapped is " << trap(arr) << endl;
}
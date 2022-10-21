/******************************************************************************
Given non-negative integers representing an elevation map where width of each bar is 1, we need to compute how much water it can trap after raining.
*******************************************************************************/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int rain_water(vector<int> a)
{
    stack<int> s;
    int n = a.size(), ans = 0;
    for(int i = 0; i< n; i++)
    {
        while(!s.empty() && a[s.top()] < a[i])
        {
            int cur = s.top();
        s.pop();
        if(s.empty())
        break;
        int diff = i - s.top() - 1;
        ans += (min(a[s.top()], a[i])- a[cur]) * diff ;
    }
    s.push(i);
    }
    return ans;
}
int main()
{
  int n, t;
  cin >> n;
    vector<int> v ;
  for(int i = 0; i < n; i++)
  {
    cin >> t;
    v.pudh_back(t) ;
  }
    cout << rain_water(v) << endl;
}

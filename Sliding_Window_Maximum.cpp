/**
* LeetCode: https://leetcode.com/problems/sliding-window-maximum/
* You are given an array of integers nums, there is a sliding window 
* of size k which is moving from the very left of the array to the very 
* right. You can only see the k numbers in the window. Each time the 
* sliding window moves right by one position.
*
* Return the max sliding window.
**/

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define si(x)           scanf("%d",&x)
#define sl(x)           scanf("%lld",&x)
#define ss(s)           scanf("%s",s)
#define pi(x)           printf("%d\n",x)
#define pl(x)           printf("%lld\n",x)
#define ps(s)           printf("%s\n",s)

#define fi              first
#define se              second
#define ll              long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mk(arr,n,type)  type *arr=new type[n];

#define deb(x)          cout << #x << "=" << x << endl
#define deb2(x, y)      cout << #x << "=" << x << "," << #y << "=" << y << endl

// C++ template to print vector container elements
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
  for (int i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i != v.size() - 1)
      os << " ";
  }
  return os;
}

/**
   vi v = {4, 3, 1, 2, 5, 3, 4, 7, 1, 9};
   int n = v.size();
   cout << maximum_sliding_window(v, 3);
**/
vector<int> maximum_sliding_window(vector<int>& v, int k)
{
  int n = v.size();

  deque<int> Q;

  vector<int> ans;

  //Initialise
  for (int i = 0 ; i < k ; i++)
  {
    while (!Q.empty() && v[i] >= v[Q.back()])
      Q.pop_back();
    Q.push_back(i);
  }

  for (int i = k ; i < n; i++)
  {
    ans.push_back(v[Q.front()]);

    if (Q.front() < i - k + 1)
      Q.pop_front();

    while (!Q.empty() && v[i] >= v[Q.back()])
      Q.pop_back();

    Q.push_back(i);
  }

  ans.push_back(v[Q.front()]);

  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);

  freopen("output.txt", "w", stdout);
#endif

  int t = 1;
  while (t--) {
    vector<int> v = {4, 3, 1, 2, 5, 3, 4, 7, 1, 9};
    cout << maximum_sliding_window(v, 3);
  }
}

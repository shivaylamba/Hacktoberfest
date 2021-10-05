// @author: Laksh Sadhwani
// Github : https://github.com/Laaaaksh
// Code : (__Name__)

#include<bits/stdc++.h>
using namespace std;
#define S 5
typedef pair<int, int> iPair;
typedef vector<int> V;
typedef vector<bool> B;
typedef tuple<int,int,int> T;
int main()
{
string s = "abc";
int n = s.size();
for(int i = 0 ; i < n ; i++)
{
	for(int j = i ; j < n ; j++)
	{
		string subs = s.substr(i,j-i+1); 
		cout << subs << endl;
	}
}
return 0;
}
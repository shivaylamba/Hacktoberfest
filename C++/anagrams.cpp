#include<iostream>
#include<vector>
#include<map>
using namespace std;

vector<int> getHashValues(string s, int i, int j)
{
	vector<int> freq(26,0);
	for(int k=i;k<=j;k++)
	{
		char ch = s[k];
		freq[ch- 'a']++;	
	}	
	return freq;
}

int anagramsSubstrings(string s)
{
	map<vector<int>,int> m;
	
	for(int i=0;i<s.length();i++)
	{
		for(int j=i;j<s.length();j++)
		{
			vector<int> h = getHashValues(s,i,j);
			m[h]++;
		}
	}
	
	int ans =0;
	for(auto p:m)
	{
		int freq = p.second;
		if(freq>=2)
			ans += (freq)*(freq-1)/2;
	}
	return ans;
}

int main()
{
	string s;
	cin>>s;
	cout<<anagramsSubstrings(s)<<endl;
	return 0;
}

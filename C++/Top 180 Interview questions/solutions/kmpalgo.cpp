#include<bits/stdc++>
using namespace std;
void kmpsearch(string &txt, string &ptr)
{
	int m = pat.size();
	int n = txt.size();
	int lps[m];
	computelpsarray(pat,m,lps);
	int i = 0;//for iterating in the text
	int j = 0; // for iterating in the pattern
	while(i<n) // iterating only O(n) time in the txt
	{
		if(pat[i]==pat[j])
		{
			i++;
			j++;
		}
		if(j==M){
			cout << "pattern found at index" << i - j;
			j=lps[j-1];
		}
		else if(i < N && pat[j]!=txt[i])
		{
			if(j!=0)
				j = lps[j-1];
			else
				i=i+1;
		}

	}
}
void computelpsarray(string &pat, int m, int lps[])
{
	int len = 0;
	// to keep the count of the index in the lps array
	lps[0] = 0;
	// always as the first character is always unique
	int i = 1;
	// starting with the character next to the first character
	while(i<M){
		if(pat[i]==pat[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
			{
				// on unequal condition we have to shift the len
				len = lps[len-1];
			}
			else
			{
				// when it reached the first index
				lps[i]=0;
				i++;
			}
		}
	}
}
int main()
{
	string txt = "geeksforgeeks";
	string ptr = "for";
	kmpsearch(txt,ptr);
}
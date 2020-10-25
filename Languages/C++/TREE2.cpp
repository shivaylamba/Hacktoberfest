//Solution for Codechef September Long challenge 2020 Division 2
//https://www.codechef.com/SEPT20B/problems/TREE2
//author: kvv1618
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    set<int>s;
	    for(int i=0;i<n;i++)
	    {
	        int x;
	        cin>>x;
	        if(x==0)
	        continue;
	        s.insert(x);
	    }
	    cout<<s.size()<<endl;
	}
	return 0;
}

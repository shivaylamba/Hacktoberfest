// Question link :- https://www.codechef.com/AUG21B/problems/OLYRANK
// Code by :- Rishav Singh Solanki


#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 	int g1,g2,s1,s2,b1,b2;
	 	cin>>g1>>s1>>b1;
	 	cin>>g2>>s2>>b2;
	 	int c1 = g1+s1+b1;
		int c2 = g2+s2+b2;
		if(c1>c2){
			cout<<1<<endl;
		}
		else{
			cout<<2<<endl;
		}


	}
}
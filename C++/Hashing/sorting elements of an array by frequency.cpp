#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> &a,pair<int,int> &b){
	if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second>b.second;
}

void func(int a[],int n){
	unordered_map<int,int> m;
	for(int i=0;i<m;i++){
		m[a[i]]++;
	}
	vector<pair<int,int>> vec;
	for(auto p:m){
		vec.push_back(p);

	}
	sort(vec.begin(),vec.end(),compare);
	for(int i=0;i<vec.size();i++){
			while(vec[i].second--){
                cout<<v[i].first;
            }
		}
		

	}
 
}
int main(){
	int t;
	cin>>t;
	for
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];

	}
	func(a,n);
	return 0;
}

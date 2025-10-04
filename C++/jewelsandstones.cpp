//ques based on stl containers, used here for hashing and string input


#include<bits/stdc++.h>
#define ll long long int 
using namespace std;
 
signed main(){
    ios::sync_with_stdio(false);
cin.tie(NULL);

string jewels; string stones;
cin>>jewels; cin>>stones;
 
        int n=jewels.size();
        int m=stones.size();
        unordered_map<char,int>mp;
        for(int i=0;i<m;i++){
            mp[stones[i]]++;
        }
        int ct=0;
        for(auto it:jewels){
            if(mp.find(it)!=mp.end()){
              ct+=mp[it];
            }
        }
      cout<<ct<<endl;
}
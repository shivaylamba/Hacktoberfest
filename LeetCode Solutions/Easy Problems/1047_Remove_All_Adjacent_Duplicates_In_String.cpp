#include<bits/stdc++.h>
class Solution {
public:
    string removeDuplicates(string s) {
    stack<char> ch;
    int i =0;
    while(i<s.size()){
        if(!ch.empty()){
            if(ch.top()==s[i]){ch.pop();}
            else{ch.push(s[i]);}
        }
        else{ch.push(s[i]);}
        i++;
    }
    string res = "";
   while(!ch.empty()){
       res+=ch.top();
       ch.pop();
   }
   reverse(res.begin(),res.end());
    return res;
    }
};
class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        int i=0;
        while(i<s.length()){
            if( ans.length() > 0 ){
                if( ans[ans.length() - 1] == s[i]){
                    ans.pop_back();
                }
                else{
                    ans.push_back(s[i]);
                }
            }
            else{
                ans.push_back(s[i]);
            }
            i++;
            
        }
        return ans;
    }
};
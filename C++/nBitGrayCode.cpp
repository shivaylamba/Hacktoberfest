


#include<bits/stdc++.h>
using namespace std;
vector<string> grayCode(int n) {
    vector<string> ans;
    if(n==0){
        ans.push_back("0");
        return ans;
    }
    if(n==1){
        ans.push_back("0");
        ans.push_back("1");
        return ans;
    }
    vector<string>pres=grayCode(n-1);
    for(int i=0;i<pres.size();i++){
        ans.push_back("0"+pres[i]);
    }
    for(int i=pres.size()-1;i>=0;i--){
        ans.push_back("1"+pres[i]);
    }
    return ans; 
}
int main(){
    int n;
    cin>>n;
    vector<string> ans = grayCode(n);
    // vector<int>ans;
    // for(string s:res){
    //     ans.push_back(stoi(s,0,2));
    // }
    // sort(ans.begin(),ans.end());
    cout<<"[";
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i];
        if(i != ans.size() - 1){
           cout<<", ";
        }
    }
    cout<<"]";
 }

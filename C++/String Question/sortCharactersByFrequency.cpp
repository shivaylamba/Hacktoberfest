#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
      
                
            sort(s.begin(),s.end(),greater<int>());
            int i=0;
            while(s[i]!='\0'){
                cout<<s[i];
                i++;
            }


    
        




        
        
        
    }
    

};

int main(){
    string str;
    cout<<"enter your string";
    cin>>str;
    Solution s1;
    s1.frequencySort(str);
    
}

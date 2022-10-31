#include <iostream> 
#include <stack>
#include <cstring>
using namespace std;

int main(){
    
    string s;
    getline(cin,s);
    
    stack<char> st;
    int flag=0;
    for(int i=0;i<s.length();i++){
    //   if(!st.empty()){
    //       cout<<st.top()<<" ";
    //   }
      if(s[i]=='('||s[i]=='{'||s[i]=='['){
          st.push(s[i]);
      }
      else if(s[i]==')'||s[i]=='}'||s[i]==']'){
          if(!st.empty() && s[i]==')' && st.top()=='('){
              st.pop();
          }
          else if(!st.empty() && s[i]==']' && st.top()=='['){
              st.pop();
          }
          else if(!st.empty() && s[i]=='}' && st.top()=='{'){
              st.pop();
          }
          else{
              cout<<"false";
              
              flag=1;
              break;
          }
      }
    }
    if(!st.empty() && flag!=1){
        cout<<"false";
    }
    if(st.empty() && flag!=1)
    cout<<"true";
    
    
    return 0;
}

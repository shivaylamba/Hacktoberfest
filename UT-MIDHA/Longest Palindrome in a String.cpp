// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
  void print(string S, int start, int end){
       for(int i= start ; i<=end;i++){
           cout<<S[i];
       }
   }
 
   string longestPalin (string S) {
       
       int l,h;
       int end =1; int start = 0;
       
       // even substring 
       
       for(int i=1;i<S.length();i++){
           l = i-1;
           h  = i;
           
           while(l>=0 && h<S.length() && S[l] == S[h]){
               
               if(h-l +1 > end){
                   start = l;
                   end = h-l +1;
                   
               }
               l--;
               h++;
           }
           
           //odd substring--
           l = i-1;
           h  = i+1;
           
           while(l>=0 && h<S.length() && S[l] == S[h]){
               
               if(h-l +1 > end){
                   start = l;
                   end = h-l +1;
                   
               }
               l--;
               h++;
           }
       }
       
       print(S,start , start+end-1);
   }
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Utkarsh Midha
  // } Driver Code Ends

#include<bits/stdc++.h>

using namespace std;

bool search(string, string, int);


 // } Driver Code Ends
//User function Template for C++

// d is the number of characters in the input alphabet 
#define d 256 

/* pat -> pattern 
	txt -> text 
	q -> A prime number 
*/
bool search(string pat, string txt, int q) 
{ 
    
   int p=pat.length();
    int t=txt.length();
     int h1=0,h2=0,flag=1;
int h=1;
for(int i=1;i<p;i++)
h=(h*d)%q;
//cout<<"h"<<h<<endl;

    for(int i=0;i<p;i++)
    {
        h1=(h1*d+pat[i])%q;
        h2=(h2*d+txt[i])%q;
    }
   // cout<<"h1"<<" "<<h1<<endl;
    //cout<<"h2"<<" "<<h2<<endl;
    for(int i=0;i<=t-p;i++)
    {
         //cout<<"h2"<<" "<<h2<<endl;
        flag=1;
         if(h2==h1)
        {
            for(int j=0;j<p;j++)
            {
                //cout<<"pat[j]"<<pat[j]<<" "<<"txt[i+j]"<<txt[i+j]<<endl;
                if(pat[j]!=txt[i+j]) 
                {
                    flag=0;
                    break;
                }
            }
           
            if(flag==1)
            return 1;
        }
        if(i<t-p)
        {
        h2=((h2-txt[i]*h)*d + txt[i+p])%q;
       
        
        if(h2<0)
        {
            //cout<<"f"<<endl;
        
        h2=h2+q;
        }
        }
       
        
    }
    
    return 0;
   
	// Your code here
}
// { Driver Code Starts.

/* Driver program to test above function */
int main() 
{ 
    int t;
    cin >> t;
    
    while(t--){
	    string s, p;
	    cin >> s >> p;
	    int q = 101; // A prime number 
	    if(search(p, s, q)) cout << "Yes" << endl;
	    else cout << "No" << endl;
    }
	return 0; 
} 
  // } Driver Code Ends

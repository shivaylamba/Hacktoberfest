//converting the string totally to smallcase
//and viceversa;

#include<bits/stdc++.h>
using namespace std;

// int main(){
//     string s1="Nehalkulshrestha";
//     for(int i=0;i<s1.length();i++){
//         if(s1[i]>='a' && s1[i]<='z'){
//             s1[i]-=32;
//         }
//     }
//     cout<<s1;
//     cout<<endl;

//     //for capital to smaller again
//     for(int i=0;i<s1.length();i++){
//         if(s1[i]>='A'&& s1[i]<='Z'){
//             s1[i]+=32;


//         }
//     }
//     cout<<s1;
// }


//alternative solution
int main(){
    string s="Nehalkulshrestha";
    transform(s.begin(),s.end(),s.begin(),::toupper);
    cout<<s;
    cout<<endl;

    transform(s.begin(),s.end(),s.begin(),::tolower);
    cout<<s;
}

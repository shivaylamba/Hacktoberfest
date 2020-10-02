// anagram strin is string which is of same size and uses all the alpahabest of the string 1 to make a another string out
// for this ive used memoizing tehcnique to solve  complexity is oreder of n(  O(n)  )
#include<bits/stdc++.h>
using namespace std;

int main(){
    char a[20]="helloworld";
    char b[20]="helloworld";

    char check[26]={0};
    for(int i=0;a[i]!='\0';i++){
        check[a[i]-97]++;
    }
     int i;
        for(i=0;b[i]!='\0';i++){
        
        if(--check[b[i]-97] < 0)
        break;
    }
     if(b[i] !='\0'){
         cout<<"not a anagram";
     }

}
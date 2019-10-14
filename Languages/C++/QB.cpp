#include<bits/stdc++.h>
using namespace std;
int main(){
    string line1, line2;
    getline(cin,line1);
    getline(cin,line2);
    int freq1[26]={0}, freq2[26]={0};
    for(int i =0;i<line1.size();i++){
        freq1[line1[i]-97]++;
    }
    for(int j = 0;j<line2.size();j++){
        freq2[line2[j]-97]++;
    }
    int count_deletions = 0;
    for(int i = 0;i<26;i++){
        count_deletions+= abs(freq1[i]-freq2[i]);
    }
    cout << count_deletions << endl;
    return 0;
}

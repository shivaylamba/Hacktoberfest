#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int i,n,k;
    vector<int>v;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>k;
        v.push_back(k);
        k=0;
    }
    sort(v.begin(),v.end());
    for(i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

    return 0;
}

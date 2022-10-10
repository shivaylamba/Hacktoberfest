#include <iostream>
#include <bits/stdc++.h> 
#include <vector>
using namespace std;

int main() {
	int n;
    cin>>n;
    
    vector<long long>vect(n);
    for(int i=0;i<n;i++){
       cin>>vect[i];
      }
     sort(vect.begin(),vect.end());
     cout<<vect[n-1]*vect[n-2];
   
      
	return 0;
}
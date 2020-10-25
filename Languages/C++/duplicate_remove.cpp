#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
	string str = "aaaaabbbbbb"; 
	sort(str.begin(), str.end()); 

	// Using unique() method 
	auto res = unique(str.begin(), str.end()); 

	cout << string(str.begin(), res) 
		<< endl; 
} 

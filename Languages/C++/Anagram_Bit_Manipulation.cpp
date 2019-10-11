#include <bits/stdc++.h> 
using namespace std; 

// Function to check whether two strings are anagram of 
// each other 
bool areAnagram(string str1, string str2) 
{ 
	// If two strings have different size 
	if (str1.size() != str2.size()) { 
		return false; 
	} 

	// To store the xor value 
	int value = 0; 

	for (int i = 0; i < str1.size(); i++) { 
		value = value ^ (int) str1[i]; 
		value = value ^ (int) str2[i]; 
	} 

	return value == 0; 

} 

// Driver code 
int main() 
{ 
	string str1 = "geeksforgeeks"; 
	string str2 = "forgeeksgeeks"; 
	if (areAnagram(str1, str2)) 
		cout << "The two strings are anagram of each other"; 
	else
		cout << "The two strings are not anagram of each other"; 

	return 0; 
} 

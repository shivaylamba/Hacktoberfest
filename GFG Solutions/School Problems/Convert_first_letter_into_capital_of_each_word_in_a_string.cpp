#include <bits/stdc++.h> 
string convertString(string str) 
{
	// WRITE YOUR CODE HERE
	int i =1, n = str.size();
	if(n==0){
		return str;
	}
	if(str[0]!=' '){
		str[0] = ::toupper(str[0]);
	}
	while(i<n){
        if(str[i]==' '){
			str[i+1] = ::toupper(str[i+1]);
		}
		i++;
	}

	return str;
}
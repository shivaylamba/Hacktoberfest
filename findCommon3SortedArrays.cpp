//time complexity---> O(n1+n2+n3)
// n1,n2,n3 are the sizes of 3 arrays
//space complexity---> O(1) as we using cout for output


#include <bits/stdc++.h> 
using namespace std; 
void findCommon(int ar1[], int ar2[], int ar3[], int n1, int n2, int n3) 
{ 

	int i = 0, j = 0, k = 0; 
	while (i < n1 && j < n2 && k < n3) 
	{ 
		// If x = y and y = z, print any of them and move ahead 
		// in all arrays 
		if (ar1[i] == ar2[j] && ar2[j] == ar3[k]) 
            cout << ar1[i] << " "; i++; j++; k++; 

		// x < y 
		else if (ar1[i] < ar2[j]) 
			i++; 
		// y < z 
		else if (ar2[j] < ar3[k]) 
			j++; 
		else
			k++; 
	} 
int main() 
{ 
	int n1,n2,n3;
    cin>>n1>>n2>>n3;
    int ar1[n1],ar2[n2],ar3[n3];
    for(int i=0;i<n1;i++)
        cin>>ar1[i];
    for(int i=0;i<n2;i++)
        cin>>ar2[i];
    for(int i=0;i<n3;i++)
        cin>>ar3[i];
	findCommon(ar1, ar2, ar3, n1, n2, n3); 
	return 0; 
} 

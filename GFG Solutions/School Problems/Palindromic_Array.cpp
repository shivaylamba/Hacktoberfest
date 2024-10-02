/*
Given a Integer array A[] of n elements. Your task is to complete the function PalinArray. Which will return 1 if all the elements of the Array are palindrome otherwise it will return 0.
Constraints:
1 <=T<= 50
1 <=n<= 20
1 <=A[]<= 10000
*/
//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;
// } Driver Code Ends
/*Complete the function below*/
class Solution {
public:
    int PalinArray(int a[], int n)
    {
    	// code here
    	for(int i=0;i<n;i++){
    	    int element = a[i];
    	    int ans =0;
    	    while(element > 0){
    	        int ld = element%10;
                 ans = ans*10 + ld;
                element /=10;
    	    }
    	    if(ans != a[i]){
    	    return 0;;
    	    }
    	}
     return 1;
    }
};
//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends
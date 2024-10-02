/*
Sum of odd and even elements
Given an integer N, find the sum of odd numbers and even numbers from 1 to N.
Your Task:

You don't need to read or print anything, Your task is to complete the function find_sum() which takes N as input parameter and returns a list of two numbers where first numbers is sum of odd numbers and second number is sum of even numbers.

Expected Time Complexity: O(1)
Expected Space Complexity:
 O(1)Constraints:
1 <= N <= 104
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution
{
	public:
		vector<int> find_sum(int n)
		{
		    // Code here
		    int odd = -1 , even = -1;
		    if(n%2==0){            // 1 2 3 4 5 6
		      odd = ((n/2)*(2*1 + (n/2 -1)*2 ))/2; // 1 3 5
		     even = ((n/2)*(2*2 + (n/2 - 1)*2))/2; // 2 4
		    }
            else{
    		     odd = ((n/2 + 1)*(2*1 + (n/2)*2 ))/2; // 1 3 5
		         even = ((n/2)*(2*2 + (n/2 - 1)*2))/2; // 2 4
            }
		    return {odd,even};

		}
};
//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	vector<int> ans = ob.find_sum(n);
    	for(auto i: ans)
    		cout << i << " ";
    	cout<<"\n";
    }
	return 0;
}
// } Driver Code Ends
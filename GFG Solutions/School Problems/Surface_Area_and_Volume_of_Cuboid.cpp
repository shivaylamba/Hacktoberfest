/*
Given length l, width b and height h of a cuboid. Find the total surface area and volume of cuboid.
 

Example 1:

Input: l = 1, b = 2, h = 3
Output: 22 6
Explanation: Surface area = 2 * (2 * 3
+ 3 * 1 + 1 * 2) = 22 and volume = 
1 * 2 * 3 = 6
Example 2:

Input: l = 2, b = 3, h = 5
Output: 62 30
Explanation: Surface area = 2 * (3 * 5
+ 5 * 2 + 2 * 3) = 62 and volume = 
2 * 3 * 5 = 30

 

Your Task:
You don't need to read or print anything. Your task is to complete the function find() which takes l, b and h as input parameter and returns a list containing the value of surface area and volume.
 

Expected Time Complexity: O(1)
Expected Space Complexity: O(1)
 

Costraints:
1 <= l, b, h <= 106
*/
//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	vector<long long int> find(int l1, int b1, int h1)
	{
	    // Code here
	    long long int l = l1 ,h=h1,b=b1;
	    long long int surface = 2*(l*b+h*b+l*h) , area = l*b*h;
	    return {surface , area};
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int l, b, h;
		cin >> l >> b >> h;
		Solution ob;
		vector<long long int> ans = ob.find(l, b, h);
		for(auto i: ans)cout << i <<" ";
		cout << "\n";
	}  
	return 0;
}
// } Driver Code Ends
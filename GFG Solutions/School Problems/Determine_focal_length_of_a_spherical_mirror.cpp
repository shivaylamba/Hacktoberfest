/*
Find the focal length of the spherical mirror with the given radius-of-curvature R.
NOTE

The focal length of the 'convex' mirror floor(-R/2) and that of the 'concave' mirror is floor(R/2).

Example 1:

Input: type = "concave", R = 5.4
Output: 2
Explanation: Focal length of concave mirror = floor(R/2) = floor(5.4/2) = floor(2.7) = 2.
Example 2:

Input: type = "convex", R = 10
Output: -5
Explanation: Focal length of convex mirror = floor(-R/2) = floor(-10/2) = floor(-5) = -5.
Your Task:
You don't need to read or print anything. Your task is to complete the function findFocalLength() which takes R and type as input parameters and returns the floor value of focal length.
 

Expected Time Complexity: O(1)
Expected Space Complexity: O(1)

Constraints:
1 <= R <= 100
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int findFocalLength(float R, string type){
	    //Code her
	    return (type=="convex")?floor(-R/2):floor(R/2);
	 
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		float n;
		string type;
		cin >> type >> n;
		Solution ob;
		int ans = ob.findFocalLength(n, type);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends
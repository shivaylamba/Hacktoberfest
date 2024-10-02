/*
Given two force vectors, find out whether they are parallel, perpendicular or neither. Let the first vector be A = a1 i +a2 j + a3 k and the second vector be B = b1 i + b2 j + b3 k.

A.B = a1 * b1 + a2 * b2 + a3 * b3

A x B = (a2 * b3 - a3 * b2) i - (a1 * b3 - b1* a3) j + (a1 * b2 - a2 * b1) k

|A|2 = a12 + a22 + a32

If A.B = 0, then A and B are perpendicular.

If |A X B|2 = 0, then A and B are parallel.

Example 1:

Input: A = 3i + 2j + k, B = 6i + 4j + 2k
Output: 1
Explanation: |A X B|2 = 0
Example 2:

Input: A = 4i + 6j + k, B = i - 1j + 2k
Output: 2
Explanation: A.B = 0
 

Your Task:
You don't need to read or print anything. Your task is to complete the function find() which takes A and B vector as parameter and returns 1 if they are parallel to each other, 2 if they are perpendicular to each other or 0 otherwise. A and B vectors will contain (a1,a2,a3) and (b1,b2,b3) respectively.
 

Expected Time Complexity: O(1)
Expected Space Complexity: O(1)
 

Constraints:
-100 <= Component <= 100
*/
//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	int find(vector<int>a, vector<int>b){
	    //  Code here
	    int prependicluar = a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
	    int parallel =  (a[1] * b[2] - a[2] * b[1])-(a[0] * b[2] - b[0]* a[2])+(a[0] * b[1]-a[1] * b[0]) ;
	   if(parallel==0){
	        return 1;
	    }
	    if(prependicluar==0){
	        return 2;
	    }
	return 0;
	    
	}
	
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>A(3), B(3);
		for(int i = 0; i < 3; i++)cin >> A[i];
		for(int i = 0; i < 3; i++)cin >> B[i];
		Solution ob;
		int ans = ob.find(A, B);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends
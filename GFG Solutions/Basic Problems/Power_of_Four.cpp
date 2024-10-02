/*
Power of Four
Given a number N, check if N is power of 4 or not.

Example 1:

Input: 
N = 64
Output: 1
Explanation:
43= 64
Example 2:

Input: 
N = 75
Output : 0
Explanation :
75 is not a power of 4.
Your task:
You don't have to read input or print anything. Your task is to complete the function isPowerOfFour() which takes an integer N and returns 1 if the number is a power of four else returns 0.
 
Expected Time Complexity: O(N)
Expected Auxiliary Space : O(1)

Constraints:
1<=N<=105
*/
//{ Driver Code Starts
#include<iostream>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int isPowerOfFour(unsigned int n)
    {
      // Your code goes here
    //   if(n==0) return 0;
      if(n==1){
          return 1;
      }
      else{
          return (n%4==0 && isPowerOfFour(n/4));
      }
    }
};

//{ Driver Code Starts.

/*Driver program to test above function*/
int main()
{
int t,n;
cin>>t;
while(t--)
{
cin>>n;
Solution ob;
if(ob.isPowerOfFour(n))
	cout<<1<<endl;
else
	cout<<0<<endl;
}
//getchar();
}

// } Driver Code Ends
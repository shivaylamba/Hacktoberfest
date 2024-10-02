/*
Given an array Arr[] of N integers.Find the sum of values of even and odd index positions separately.

Example 1:

Input:
N=5
Arr={1,2,3,4,5}
Output:
9 6
Explanation:
The sum of elements at odd places i.e
at 1st,3rd and 5th places are (1+3+5=9)
Similarly,the sum of elements at even 
places i.e. at 2nd and 4th places are
(2+4=6).
Example 2:

Input:
N=5
Arr={1,1,1,1,1}
Output:
3 2
Explanation:
The sum of elements at odd places
is (1+1+1=3).Similarly, the sum of
elements at even places is (1+1=2)

Your Task:
You don't need to read input or print anything.Your Task is to complete the function EvenOddSum() which takes an integer N and an array Arr as input parameters and returns the sum of elements in odd places and in even places separately.
 

Expected Time Complexity:O(N)
Expected Auxillary Space:O(1)

Constraints:
1<=N<=105
0<=Arr[i]<=104,for 0<=i
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> EvenOddSum(int N, int Arr[]) {
        // code here
     int evens= 0 , odds = 0;
     for(int i = 1; i<=N;i++){
         if(i%2==0){
             evens+=Arr[i-1];
         }
         else{
             odds+=Arr[i-1];
         }
     }
     return {odds,evens};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int Arr[N];
        for (int i = 0; i < N; i++) cin >> Arr[i];
        Solution ob;
        vector<int> ans = ob.EvenOddSum(N, Arr);
        cout << ans[0] << " " << ans[1] << "\n";
    }
}
// } Driver Code Ends
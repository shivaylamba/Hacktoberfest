/*
Missing number
Ritu has all numbers from 1 to n in an array arr of length n-1 except one number. You have to find which number, Ritu doesn't have from 1 to n.

NOTE: Don't use Sorting

Example 1:

Input:
n  =  4                                        
arr = {1, 4, 3}
Output: 2     
Explanation:
Ritu doesn't have number 2
Example 2:

Input:                        
n = 5
arr = {2, 5, 3, 1}
Output: 4
Explanation:
Ritu doesn't have number 4 in her collection
Your Task:  
You don't need to read input or print anything. Your task is to complete the function missingNumber() which takes an integer n and an array arr of length n-1 as inputs and returns the missing number.

Exected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
2 ≤ n ≤ 104
1 ≤ arr[i] ≤ n
Size(arr) = n-1 
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
// Optimized Approach
// Time Complexity O(n)
// Space Complexity O(1)
class Solution {
  public:
    int missingNumber(int n, vector<int> &arr) {
        // code here
        int sumAct = (n*(n+1))/2;
        int sumArr = 0;
        for(int x:arr){
            sumArr+=x;
        }
        return abs(sumArr-sumAct);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> arr(n-1);
        Array::input(arr,n-1);
        
        Solution obj;
        int res = obj.missingNumber(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
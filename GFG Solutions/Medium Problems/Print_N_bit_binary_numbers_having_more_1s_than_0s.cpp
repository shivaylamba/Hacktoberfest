/*
Print N-bit binary numbers having more 1s than 0s
Given a positive integer n. Your task is to generate a string list of all n-bit binary numbers where, for any prefix of the number, there are more or an equal number of 1's than 0's. The numbers should be sorted in decreasing order of magnitude.

Example 1:

Input:  
n = 2
Output: 
"11, 10"
Explanation: Valid numbers are those where each prefix has more 1s than 0s:
11: all its prefixes (1 and 11) have more 1s than 0s.
10: all its prefixes (1 and 10) have more 1s than 0s.
So, the output is "11, 10".
Example 2:

Input:  
n = 3
Output: 
"111, 110, 101"
Explanation: Valid numbers are those where each prefix has more 1s than 0s.
111: all its prefixes (1, 11, and 111) have more 1s than 0s.
110: all its prefixes (1, 11, and 110) have more 1s than 0s.
101: all its prefixes (1, 10, and 101) have more 1s than 0s.
So, the output is "111, 110, 101".
User Task:
Your task is to complete the function NBitBinary() which takes a single number as input n and returns the list of strings in decreasing order. You need not take any input or print anything.

Expected Time Complexity: O(|2n|)
Expected Auxiliary Space: O(2n)

Constraints:
1 <= n <= 15
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function to get the binary representation
// of the number N
string getBinaryRep(int N, int num_of_bits)
{
    string r = "";
    num_of_bits--;
   
    // loop for each bit
    while (num_of_bits >= 0) 
    {
        if (N & (1 << num_of_bits))
            r.append("1");
        else
            r.append("0");
        num_of_bits--;
    }
    return r;
}
 
vector<string> NBitBinary(int N)
{
    vector<string> r;
    int first = 1 << (N - 1);
    int last = first * 2;
     
    // generate numbers in the range of (2^N)-1 to 2^(N-1)
    // inclusive
    for (int i = last - 1; i >= first; --i)
    {
        int zero_cnt = 0;
        int one_cnt = 0;
        int t = i;
        int num_of_bits = 0;
         
        // longest prefix check
        while (t) 
        {
            if (t & 1)
                one_cnt++;
            else
                zero_cnt++;
            num_of_bits++;
            t = t >> 1;
        }
       
        // if counts of 1 is greater than
        // counts of zero
        if (one_cnt >= zero_cnt)
        {
            // do sub-prefixes check
            bool all_prefix_match = true;
            int msk = (1 << num_of_bits) - 2;
            int prefix_shift = 1;
            while (msk) 
            {
 
                int prefix = (msk & i) >> prefix_shift;
                int prefix_one_cnt = 0;
                int prefix_zero_cnt = 0;
                while (prefix)
                {
                    if (prefix & 1)
                        prefix_one_cnt++;
                    else
                        prefix_zero_cnt++;
                    prefix = prefix >> 1;
                }
                if (prefix_zero_cnt > prefix_one_cnt)
                {
                    all_prefix_match = false;
                    break;
                }
                prefix_shift++;
                msk = msk & (msk << 1);
            }
            if (all_prefix_match)
            {
                r.push_back(getBinaryRep(i, num_of_bits));
            }
        }
    }
    return r;
}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends
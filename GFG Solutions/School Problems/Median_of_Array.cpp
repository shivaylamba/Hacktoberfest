/*
Given an array arr[] of N integers, calculate the medianYour Task:
You don't need to read or print anything. Your task is to complete the function find_median() which takes the array as input parameter and returns the floor value of the median.
 

Expected Time Complexity: O(n * log(n))
Expected Space Complexity: O(1)
 

Constraints:
1 <= Length of Array <= 100
1 <= Elements of Array <= 100
*/
/*
Mean of an array = (sum of all elements) / (number of elements)
To find median:
First, simply sort the array
Then, check if the number of elements present in the array is even or odd
If odd, then simply return the mid value of the array
Else, the median is the average of the two middle values
To find Mean:
At first, find the sum of all the numbers present in the array.
Then, simply divide the resulted sum by the size of the array
Complexity Analysis:

Time Complexity to find mean: O(N) 
Time Complexity to find median: O(N Log N) as we need to sort the array first. 
Auxiliary Space: O(1)
*/
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends
class Solution
{
public:
	public:
		int find_median(vector<int> v)
		{
		    // Code here.
		    int mid;
		    sort(v.begin(),v.end());
		    mid = (v.size()-1)/2;
		    if(v.size()%2==0){
		        mid = (v[mid]+v[mid+1])/2;
		        return mid;
		    }
		    else{
		  return v[mid];
		    }
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
    	vector<int> v(n);
    	for(int i = 0; i < n; i++)
    		cin>>v[i];
    	Solution ob;
    	int ans = ob.find_median(v);
    	cout << ans <<"\n";
    }
	return 0;
}
// } Driver Code Ends
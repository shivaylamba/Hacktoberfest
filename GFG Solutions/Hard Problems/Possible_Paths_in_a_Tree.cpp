/*
Possible Paths in a Tree
Given a weighted tree with n nodes and (n-1) edges. You are given q queries. Each query contains a number x. For each query, find the number of paths in which the maximum edge weight is less than or equal to x.

Note: Path from A to B and B to A are considered to be the same.

Example 1:

Input: 
n = 3
edges {start, end, weight} = {{1, 2, 1}, {2, 3, 4}}
q = 1
queries[] = {3}
Output: 
1
Explanation:
Query 1: Path from 1 to 2
Example 2:

Input: 
n = 7
edges {start, end, weight} = {{1, 2, 3}, {2, 3, 1}, {2, 4, 9}, {3, 6, 7}, {3, 5, 8}, {5, 7, 4}}
q = 3
queries[] = {1, 3, 5}
Output: 
1 3 4
Explanation: 
Query 1: Path from 2 to 3
Query 2: Path from 1 to 2, 1 to 3, and 2 to 3
Query 3: Path from 1 to 2, 1 to 3, 2 to 3, and 5 to 7
Your Task:  
You don't need to read input or print anything. Complete the function maximumWeight()which takes integers n, list of edges where each edge is given by {start,end,weight}, an integer q and a list of q queries as input parameters and returns a list of integers denoting the number of possible paths for each query. 

Expected Time Complexity: O(nlogn + qlogn)
Expected Auxiliary Space: O(n)

Constraints:
2 ≤ n ≤ 104
1 ≤ q ≤ 104
1 ≤ edges[i][0], edges[i][1] ≤ n
edges[i][0] != edges[i][1]
0 ≤ edges[i][2] ≤ 105
0 ≤ queries[i] ≤ 105
*/
//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    int ans;

	private:
	//Function to find the root of the given element in the disjoint set.
	int root(int i, vector<int> &parent)
	{
	    while(parent[i]!=i)
	    {
	        parent[i] = parent[parent[i]];
	        i = parent[i];
	    }
	    return i;
	}

	//Function to perform union operation of two sets and return the resulting size of the set.
    int Union(int a, int b, vector<int> &parent, vector<int> &sz)
    {
    	int ra = root(a, parent);
	    int rb = root(b, parent);
	    
	    //If the roots are the same, it means they are already in the same set,
	    //so return the current size of the set.
	    if(ra == rb)
	        return sz[ra]*sz[ra];
	    
	    //If the size of the set containing a is smaller than the size of the set containing b,
	    //then swap a and b.
	    if(sz[ra] < sz[rb])
	    {
	        swap(ra,rb);
	        swap(a,b);
	    }
	    
	    //Merge the two sets by updating the parent and size.
	    ans += sz[ra]*sz[rb];
	    parent[rb] = ra;
	    sz[ra] += sz[rb];
	 
	    return ans;
    }
	public:
	  // code here
	    vector<int> maximumWeight(int n, vector<vector<int>> edges, int q, vector<int> &queries)
	{
		ans = 0;

		vector<int> parent(n+1, 0), sz(n+1, 0);
		for(int i = 0;i <= n; i++)
		{
            //Initializing each element as its own parent and size as 1.
            parent[i] = i;
            sz[i] = 1;
        }

        //Creating a vector of pairs to store the weights and the endpoints of the edges.
        vector<pair<int, pair<int, int>>> wt;
       	for(int i = 0; i < n-1; i++)
           	wt.push_back({edges[i][2] , {edges[i][0], edges[i][1]}}); 
        
        //Sorting the edges based on their weights in ascending order.
        sort(wt.begin() , wt.end());

        //Creating a map to store the maximum weight of the connected component with weights less than or equal to each query.
        map<int, int> mp;

        //Iterating through the sorted edges and performing union operation.
        for(int i = 0;i < n-1; i++){
            int a = wt[i].first;
            int b = wt[i].second.first;
            int c = wt[i].second.second;
 
            //Updating the map with the maximum weight of the connected component after each union operation.
            mp[a] = Union(b, c, parent, sz);  
        }

        //Creating a vector to store the results for each query.
        vector<int> res;

        //Iterating through each query and finding the maximum weight with weights less than or equal to the query.
        for(int i = 0; i < q; i++)
        {
           	//Finding the element in the map which is just greater than the query.
           	auto val = mp.upper_bound(queries[i]);
            if(val == mp.begin())
                res.push_back(0); //If there is no such element, then the maximum weight is 0.
            else
            {
                val--;
                res.push_back(val->second); //Storing the maximum weight for the query.
            }
       	}
       	return res;
	}
};



//{ Driver Code Starts.

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
        cin >> n;
        
        vector<vector<int>> edges(n-1, vector<int> (3, 0));

        for(int i = 0; i < n-1; i++)
        {
        	for(int j = 0; j < 3; j++)
        	{
        		cin >> edges[i][j];
        	}
        }

        int q;
        cin >> q;
        vector<int> queries(q);
        for(int i = 0; i < q; i++)
        	cin >> queries[i];

    	Solution obj;
    	vector<int> ans = obj.maximumWeight(n, edges, q, queries);

    	for(auto i:ans)
    		cout << i << " ";
    	cout << "\n"; 
    }
    return 0;
}

// } Driver Code Ends
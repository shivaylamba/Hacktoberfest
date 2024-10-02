/*
Find all pairs with a given sum
Given two unsorted arrays A of size N and B of size M of distinct elements, the task is to find all pairs from both arrays whose sum is equal to X.
Note: All pairs should be printed in increasing order of u. For eg. for two pairs (u1,v1) and (u2,v2), if u1 < u2 then
(u1,v1) should be printed first else second.
Example 1:
Input:
A[] = {1, 2, 4, 5, 7}
B[] = {5, 6, 3, 4, 8} 
X = 9 
Output: 
1 8
4 5 
5 4
Explanation:
(1, 8), (4, 5), (5, 4) are the
pairs which sum to 9.
Example 2:
Input:
A[] = {-1, -2, 4, -6, 5, 7}
B[] = {6, 3, 4, 0} 
X = 8 
Output:
4 4 
5 3
Your Task:  
You don't need to read input or print anything. Your task is to complete the function allPairs() which takes the array A[], B[], its size N and M respectively, and an integer X as inputs and returns the sorted vector pair values of all the pairs u,v where u belongs to array A and v belongs to array B. If no such pair exists return empty vector pair
Expected Time Complexity: O(NLog(N))
Expected Auxiliary Space: O(N)
Constraints:
1 ≤ N, M ≤ 106
-106 ≤ X, A[i], B[i] ≤ 106
*/
class Solution{
    public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        // Your code goes here  
        vector<pair<int,int>> ans;
        unordered_map<int,int> map;
        for(int i = 0 ; i<M;i++){
            map[B[i]]++;
        }

        // Or We can Sort Here
        // sort(A,A+N);
        for(int i=0;i<N;i++){
            int temp = X - A[i];
            if(map.find(temp)!=map.end()){
                ans.push_back({A[i],temp});
            }
        }
       
        sort(ans.begin(),ans.end());
        return ans;
    }
};
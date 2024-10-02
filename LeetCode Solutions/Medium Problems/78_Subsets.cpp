/*
78. Subsets
Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.
Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:
Input: nums = [0]
Output: [[],[0]]
Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/
/*
----------------------------Most Optimized Approach-------------------------------------------
Complexity Analysis:
    Time Complexity: O(N*2^N), where n is the size of given array.
    Auxiliary Space:
        O(N) : if we only print our subsets, there will at max N recursion stack
        O(2^N) : if we would store all the subsets we will need 2^N memory blocks to store each subset
*/

class Solution {
private:
    void solve(vector<int>nums,vector<int>output,int index,vector<vector<int>>&ans){
        if(index>=nums.size()){
            ans.push_back(output);
             return;
             }
        // Exclude case
        solve(nums,output,index+1,ans);
        output.push_back(nums[index]);
        solve(nums,output,index+1,ans);

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> output;
        vector<vector<int>> ans;
        int index = 0;
        solve(nums,output,index,ans);
        return ans;
    }
};
/*
----------------------------Most Optimized Approach-------------------------------------------
Complexity Analysis:
    Time Complexity: O(N*2^N), where n is the size of given array.
    Auxiliary Space:
        O(N) : if we only print our subsets, there will at max N recursion stack
        O(2^N) : if we would store all the subsets we will need 2^N memory blocks to store each subset
*/
class Solution {
    void helper(vector<int>& nums,vector<int>out,vector<vector<int>>& ans){
        if(nums.size()==0){
            ans.push_back(out);
            return;
        }
        int temp = nums.back();
        nums.pop_back();
        out.push_back(temp);
        helper(nums,out,ans); //pick

        out.pop_back();
        helper(nums,out,ans); //not pick
        nums.push_back(temp);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>out;
        helper(nums,out,ans);

        return ans;
    }
};
/*
----------------------------Printing all Subsets Using Bit Manipulation-----------------------------
Complexity Analysis:
        Time Complexity: O(N*2^N), where n is the size of given array.
        Auxiliary Space:
                O(N) : if we only print our subsets, there will at max N recursion stack
                O(2^N) : if we would store all the subsets we will need 2^N memory blocks to store each subset
*/
void findSubsets(int nums[], int n)
{
    // Loop through all possible subsets using bit manipulation
    for (int i = 0; i < (1 << n); i++) {

        // Loop through all elements of the input array
        for (int j = 0; j < n; j++) {

            // Check if the jth bit is set in the current subset
            if ((i & (1 << j)) != 0) {

                // If the jth bit is set, add the jth element to the subset
                cout << nums[j] << " ";
            }
        }

        cout << endl;
    }
}

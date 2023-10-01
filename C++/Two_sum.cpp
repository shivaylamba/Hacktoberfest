#include <bits/stdc++.h>
using namespace std; 

// Function to find two numbers that add up to a target sum
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> Nums; // Store number-index pairs
    vector<int> result; // Store the result indices

    // Iterate through the input vector
    for (int i = 0; i < nums.size(); ++i) {
        int  Diff = target - nums[i]; // Calculate the  Diff
        if (Nums.find( Diff) != Nums.end()) {
            // If  Diff exists in the map, we found a solution
            result.push_back(Nums[ Diff]);
            result.push_back(i);
            break; // Exit the loop
        }
        Nums[nums[i]] = i; // Store the current number and its index
    }

    return result;
}

int main() {
    vector<int> nums = {72,4,2,5,3,4,2,15,3,16};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    if (result.size() == 2) {
        cout << "Indices of the two numbers that add up to " << target << ": " << result[0] << " and " << result[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}

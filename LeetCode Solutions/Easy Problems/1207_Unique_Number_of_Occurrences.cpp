/*
1207. Unique Number of Occurrences
Given an array of integers arr, return true if the number of occurrences 
of each value in the array is unique or false otherwise.
Example 1:
Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values 
have the same number of occurrences.
Example 2:
Input: arr = [1,2]
Output: false
Example 3:
Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true
Constraints:
1 <= arr.length <= 1000
-1000 <= arr[i] <= 1000
*/
/*
=> Efficient Approach: The idea is to use Hashing. Below are the steps:
   - Traverse the given array arr[] and store the frequency of each element in a Map.
   - Now traverse the map and check if the count of any element occurred more than once.
   - If the count of any element in the above steps is more than one then print “No”, else print “Yes”.
Below is the implementation of the above approach:
    => Time Complexity: O(N), where N is the number of elements in the array.
    => Auxiliary Space: O(N) 
*/
class Solution
{
    public:
    // Time Complexity O(n*log(n))
    // Space Complexity O(n)
    bool isFrequencyUnique(int n, int arr[])
    {
        unordered_map<int,int> f;
        for(int i=0;i<n;i++){
            f[arr[i]]++;
        }
        unordered_set<int> s;
        for(auto& i:f){
            if(s.count(i.second)) return 0;
            else s.insert(i.second);
        }
        return 1;
    }
};
/*
    => Another Approach (set):
   - We can traverse the array and count the frequency of each element using a hash map. 
    Then, we can insert the frequencies into a set and check if the size of the set is 
    equal to the number of distinct frequencies. If yes, then all the frequencies are 
    unique, otherwise not.
Below is the implementation of the above approach:
    => Time Complexity: O(N), where N is the number of elements in the array.
    => Auxiliary Space: O(N) 
*/
class Solution
{
    public:
    // Time Complexity O(n*log(n))
    // Space Complexity O(n)
    bool isFrequencyUnique(int n, int arr[])
    {
        unordered_map<int,int> f;
        for(int i=0;i<n;i++){
            f[arr[i]]++;
        }
        set<int> freqSet;
        for(auto& i:f){
            freqSet.insert(i.second);
        }
        return freqSet.size()==f.size();
    }
};
/*
Brute Forces
*/
    // Time Complexity O(n*log(n))
    // Space Complexity O(1)
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int> v;

        for (int i = 0; i < arr.size(); i++) {
            int cnt = 1;

            // Count occurrences of the current element
            while (i + 1 < arr.size() && arr[i] == arr[i + 1]) {
                cnt++;
                i++;
            }

            v.push_back(cnt);
        }

        sort(v.begin(), v.end());

        for (int i = 1; i < v.size(); i++) {
            if (v[i] == v[i - 1]) {
                return false;
            }
        }

        return true;
    }
}; 
class Solution
{
    public:
    // Time Complexity O(n*log(n))
    // Space Complexity O(n)
    bool isFrequencyUnique(int n, int arr[])
    {
        map<int,int> f;
        for(int i=0;i<n;i++){
            f[arr[i]]++;
        }
        vector<int> ans;
        for(auto i:f){
            ans.push_back(i.second);
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]==ans[i+1]) return 0;
        }
        return 1;
    }
};

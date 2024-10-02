/*
Unique Number of Occurrences
Given an array arr of N integers, the task is to check whether the frequency of the elements in the array is unique or not. Or in other words, there are no two distinct numbers in array with equal frequency. If all the frequency is unique then return true, else return false.

Example 1:

Input:
N = 5
arr = [1, 1, 2, 5, 5]
Output:
false
Explanation:
The array contains 2 (1’s), 1 (2’s) and 2 (5’s), since the number of frequency of 1 and 5 are the same i.e. 2 times. Therefore, this array does not satisfy the condition.
Example 2:

Input:
N = 10
arr = [2, 2, 5, 10, 1, 2, 10, 5, 10, 2]
Output:
true
Explanation:
Number of 1’s -> 1
Number of 2’s -> 4
Number of 5’s -> 2
Number of 10’s -> 3.
Since, the number of occurrences of elements present in the array is unique. Therefore, this array satisfy the condition.
Your task:
You don't need to read input or print anything. Your task is to complete the function isFrequencyUnique() which take integer N and array arr of size N as arguments, and returns a boolean.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= N <=105
-109 <= arr[i] <= 109
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
/*
3184. Count Pairs That Form a Complete Day I
Given an integer array hours representing times in hours, return an integer denoting the number of pairs i, j where i < j and hours[i] + hours[j] forms a complete day.
A complete day is defined as a time duration that is an exact multiple of 24 hours.
For example, 1 day is 24 hours, 2 days is 48 hours, 3 days is 72 hours, and so on.
Example 1:
Input: hours = [12,12,30,24,24]
Output: 2
Explanation:
The pairs of indices that form a complete day are (0, 1) and (3, 4).
Example 2:
Input: hours = [72,48,24,3]
Output: 3
Explanation:
The pairs of indices that form a complete day are (0, 1), (0, 2), and (1, 2).
Constraints:
1 <= hours.length <= 100
1 <= hours[i] <= 109
*/
/*
    OPTMIZED APPROACH
Time Complexity O(n)
Space Complexity O(n)

*/
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans = 0;
        vector<int> count(24);
        for(int i = 0; i < hours.size(); i++) {
            ans += count[(24 - hours[i] % 24) % 24];
            count[hours[i] % 24]++;
        }
        return ans;
    }
};
//------------------------------------------------------------------------------------------------//
class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int count = 0;
        unordered_map<int,int> map;
        for(int i = 0 ; i<hours.size();i++){
          int rem = hours[i]%24;
            if(rem) count+=map[24-rem];
            else count+=map[0];
            map[rem]++;
        }
        return count ;
    }
};
/*
    BRUTE FORCE
Time Complexity O(n^(n-1))
Space Complexity O(1)
*/
class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int i = 0 , j = i+1 , count=0;
        while(i<hours.size()-1 && j<hours.size()){
            int sum = hours[i]+hours[j];
            if(sum%24==0) count++;
            j++;
            if(j==hours.size()){i++;j=i+1;}
        }
        return count ;
    }
};
/*
    BRUTE FORCE
Time Complexity O(n^2)
Space Complexity O(1)
*/
class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int count = 0 ;
        for(int i = 0 ; i<hours.size()-1;i++){
            for(int j = i+1;j<hours.size();j++){
                if((hours[i]+hours[j])%24==0) count++;
            }
        }
        return count ;
    }
};
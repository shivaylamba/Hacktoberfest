class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      int n = nums.size();
        // declaring the answer vector
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        // keeping 1 number constant
        for(int i = 0 ; i < n-2 ; i++)
        {
            if(i==0 || (i > 0 && nums[i]!=nums[i-1]))
            {
                int low = i+1;
                int high = n-1;
                int sum = 0 - nums[i];
                // iterating in the rest of the array
                while(low < high)
                {
                    if(nums[low] + nums[high] == sum)
                    {
                        vector<int> answer;
                        answer.push_back(nums[i]);
                        answer.push_back(nums[low]);
                        answer.push_back(nums[high]);
                        res.push_back(answer);
                    
                    while(low < high &&(nums[low]==nums[low+1])) low++;
                    while(low < high &&(nums[high]==nums[high-1])) high--;
                    low++;
                    high--;
                    }
                    else if(nums[low] + nums[high] > sum) high--;
                    else low++;
                }// while loops ends
            }
        }//for loop end
        return res;
    }
};
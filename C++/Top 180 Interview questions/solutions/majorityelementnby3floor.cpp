class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // here we will use the modified boyer moore voting algorithm
        int sz = nums.size();
        // take the size of the vector
        int num1  = INT_MIN;
        int num2 = INT_MIN;
        // this initialization is important
        int count1=0;
        int count2=0;
        for(int i = 0 ; i < sz ; i++)
        {
            if(num1==nums[i])
                count1++;
            else if(num2==nums[i])
                count2++;
            else if(count1==0)
            {
                num1 = nums[i];
                count1=1;
            }
            else if(count2==0)
            {
                num2=nums[i];
                count2=1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        // so we can have either the num1 or the num2 as the answer
        count1 = 0;
        count2=0;
        // counting the occurence of the num1 and the num
        for(int i = 0 ; i < sz ; i++)
        {
            if(nums[i]==num1)
                count1++;
            if(nums[i]==num2)
                count2++;
        }
        vector<int>finalAns;
        if(count1 > sz /3)
            finalAns.push_back(num1);
        if(count2 > sz /3)
            finalAns.push_back(num2);
        return finalAns;
    }
};
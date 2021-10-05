class Solution {
public:
    void swap(int* a, int* b)
    {
        int temp = *a;
        *a=*b;
        *b=temp;
    }
    void moveZeroes(vector<int>& nums) {
        int j=0; 
        int n= nums.size();
        int k= n-1;
        while(j<k)
        {
            if(nums[j]==0)
            {
                 swap(&nums[j],&nums[k]);
                 k--;
            }
            else
                j++;
        }
    }
};

// here the relative order won't be maintained.
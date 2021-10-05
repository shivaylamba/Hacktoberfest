class Solution {
public:
    int gcd(int a, int b)
    {
    if(a==0)
        return b;
    else
        return(b%a,a);
        // here a is smaller
    }

    void rotate(vector<int>& nums, int k) {
        int a = k;
        int b = nums.size();
       int d = gcd(a,b);
        int i=0;
        while( i < d){
        int temp=nums[i];
        int j = i;
            while(1){
            int val = j + k;
                if(k >=n)
                    k=k-n;
                if(k==i)
                    break;
                nums[j]=nums[val];
                j=val;
            }
            nums[j]=temp;
        }
        return nums;
    }
};
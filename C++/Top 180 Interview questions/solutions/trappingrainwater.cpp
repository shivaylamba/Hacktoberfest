class Solution {
public:
    int trap(vector<int>& height) {
        // intializing everything
        int n = height.size();
        int leftmax=0;
        int rightmax=0;
        int left = 0;
        int right = n-1;
        int res = 0;
        //using the 2 pointer approach
        while(left<=right)
        {
          if(height[left]<=height[right])
          {
             if(leftmax<=height[left]) leftmax = max(leftmax, height[left]);
             else res+=(leftmax-height[left]);
             left++;
          }
          else
          {
            if(rightmax<=height[right]) rightmax = max(rightmax, height[right]);
             else res+=(rightmax-height[right]);
             right--;   
          }
        }// while loop ends
        
        return res;
    }
};
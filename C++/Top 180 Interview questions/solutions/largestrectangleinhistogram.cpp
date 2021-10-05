class Solution {
public:
    void funcleft(vector<int>& left, stack<pair<int,int>>& s, vector<int>& heights, int n){
        for(int i= 0 ; i < n ; i++)
        {
            while(s.empty()==false && s.top().first >= heights[i])
                s.pop();
            if(!s.empty())
                left[i] = s.top().second;
            s.push(make_pair(heights[i],i));
        }
    }
     void funcright(vector<int>& right, stack<pair<int,int>>& s, vector<int>& heights, int n){
        for(int i= n-1 ; i>=0 ; i--)
        {
            while(s.empty()==false && s.top().first >= heights[i])
                s.pop();
            if(!s.empty())
                right[i] = s.top().second;
            s.push(make_pair(heights[i],i));
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int maxArea= 0;
        int n = heights.size();
        vector<int> left(n, -1);
        vector<int>right(n,n);
        stack<pair<int,int>> s1;
        stack<pair<int,int>> s2;
        funcleft(left,s1,heights,n);
        funcright(right,s2,heights,n);
        for(int i = 0 ; i < n ; i++)
        {
            maxArea = max(maxArea , (heights[i] *(right[i]-left[i] - 1)));
        }
        return maxArea;
    }
};
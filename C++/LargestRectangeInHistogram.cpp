class Solution {
public:

    vector <int> nsel(vector<int> arr, int n){
        vector<int> nselIndex;
        stack<pair<int, int>> s;

        for(int i=0; i<n; i++){
            while(!s.empty() && s.top().first >= arr[i]){
                s.pop();
            }
            if(s.empty()){
                nselIndex.push_back(-1);
            }
            else{
                nselIndex.push_back(s.top().second);
            }
            s.push({arr[i], i});
        }
        return nselIndex;
    }

    vector <int> nser(vector<int> arr, int n){
        vector<int> nserIndex;
        stack<pair<int, int>> s;

        for(int i=n-1; i>=0; i--){
            while(!s.empty() && s.top().first >= arr[i]){
                s.pop();
            }
            if(s.empty()){
                nserIndex.push_back(n);
            }
            else{
                nserIndex.push_back(s.top().second);
            }
            s.push({arr[i], i});
        }
        reverse(nserIndex.begin(), nserIndex.end());
        return nserIndex;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nselIndex =  nsel(heights, n);
        vector<int> nserIndex =  nser(heights, n);
        vector<int> ans;
        int max = INT_MIN;

        for(int i=0; i<n; i++){
            ans.push_back((nserIndex[i] - nselIndex[i] - 1) * heights[i]);
            if(max < ans[i]){
                max = ans[i];
            }
        }
        return max;
    }
};

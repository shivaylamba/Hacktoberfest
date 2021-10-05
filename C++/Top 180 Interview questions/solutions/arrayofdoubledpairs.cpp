class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
       unordered_map<int,int> um;
       for(auto it : arr)
           um[it]++;
      sort(arr.begin(),arr.end());
       for(auto it : arr)
       {
           if(um[it] && um[2*it])
           {
               um[it]--;
               um[2*it]--;
           }
       }
        for(auto [a,b] : um)
            if(b) return false;
        return true; 
    }
};          
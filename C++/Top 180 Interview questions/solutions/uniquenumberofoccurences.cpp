class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
     unordered_map<int,int> um;
        for(auto it : arr)
            um[it]++;
     unordered_set<int> s;
     for(auto it : um)
     {
         if(s.find(it.second)==s.end())
             s.insert(it.second);
         else
             return false;
     }
        return true;
    }
};
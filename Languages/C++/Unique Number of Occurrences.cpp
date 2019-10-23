class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int size=arr.size();
       unordered_map<int,int> map;
        unordered_set<int> count;
        for(int i=0;i<size;i++){
            if(map.find(arr[i])==map.end())
                //if not foundL
                //add
                map[arr[i]]=1;
            else
                //increase count
                map[arr[i]]++;
        }
        
        //check for occurences
        for(auto it=map.begin();it!=map.end();it++){
            if(count.find(it->second)!=count.end())
                return false;
            //else::
            else
            count.insert(it->second);
        }
        return true;
    }
};

vector<int> Solution::dNums(vector<int> &arr, int b) {
    vector<int> res;
    if(b > arr.size())
        return res;
    unordered_map<int,int> um;
    for(int i = 0 ; i < arr.size(); i++)
    {
       um[arr[i]]++;
       if((i+1)>=b)
       {
           res.push_back(um.size());
           um[arr[i-b+1]]--;
           if(um[arr[i-b+1]]==0)
            um.erase(arr[i-b+1]);
       } 
    }
    return res;
}

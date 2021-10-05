class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& A) {
    int n = A.size();
    vector<int> ves;
    vector<int> res(n+1,0);
    for(int i = 0 ; i < n ; i++)
    {
        res[A[i]] = 1;
    }
    for(int i = 1 ; i < n + 1 ; i++)
    {
        if(res[i]==0)
            ves.push_back(i);
    }
        return ves;
    }
};
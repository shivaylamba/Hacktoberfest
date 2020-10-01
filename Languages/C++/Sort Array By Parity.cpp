class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> odd;
        vector<int> even;
        for(int obj : A){
            if(obj%2==0)
                even.push_back(obj);
            else
                odd.push_back(obj);
        }
        for(int obj : odd){
            even.push_back(obj);
        }
        
        return even;
        
    }
};

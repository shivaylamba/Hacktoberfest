class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left =0;
        int right =0;
        int maxans =0;
        int n = fruits.size();
        map<int, int> freq;
        for(int i=0; i<n; i++){
            freq[fruits[i]]++;
            while(freq.size()>2){
                freq[fruits[left]]--;
                if(freq[fruits[left]]==0){
                    freq.erase(fruits[left]);
                }
                left++;
            }
            maxans = max(maxans, i-left+1);
        }
        return maxans;
    }
};

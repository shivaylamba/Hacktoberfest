class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int countone = 0;
        int countflips = 0;
        for(auto it : s)
        {
            if(it=='1')
                countone++;
            else
                countflips++;
            countflips = min(countflips,countone);
        }
        return countflips;
    }
};
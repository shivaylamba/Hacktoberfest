class Solution {
public:
    string intToRoman(int num) {
      string s = "";
      vector<pair<int,string>> v;
        v.push_back({1,"I"});
        v.push_back({4,"IV"});
        v.push_back({5,"V"});
        v.push_back({9,"IX"});
        v.push_back({10,"X"});
        v.push_back({40,"XL"});
        v.push_back({50,"L"});
        v.push_back({90,"XC"});
        v.push_back({100,"C"});
        v.push_back({400,"CD"});
        v.push_back({500,"D"});
        v.push_back({900,"CM"});
        v.push_back({1000,"M"});
        int n = v.size();
        int i = n -1;
        while(num)
        {
        int temp = v[i].first;
            if(num>=temp)
            {
                int var = num / temp;
                while(var--)
                {
                    s+=v[i].second;
                }
                num = num%temp;
            }
            i--;
        }
        return s;
    }
};
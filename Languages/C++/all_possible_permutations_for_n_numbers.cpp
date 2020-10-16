#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

/*n=3
3
1 3 6
1 3 6 
1 6 3 
3 1 6 
3 6 1 
6 1 3 
6 3 1
*/


vector<vector<int>> permute(vector<int> &num)
{
    if(num.size()<=1)
    return {num};
    vector<vector<int>> result;
    for(int i=0;i<num.size();i++)
    {
        vector<int>v(num.begin(),num.end());
        v.erase(v.begin()+i);
        auto res=permute(v);

        for(int j=0;j<res.size();j++)
        {
            vector<int> _v=res[j];
            _v.insert(_v.begin(),num[i]);
            result.push_back(_v);
        }
    }
    return result;
}

int32_t main(){
fast

int n;
cin>>n;
vector<int> v;
rep(i,n)
{
    int num;
    cin>>num;
    v.push_back(num);
}
vector<vector<int>> res=permute(v);
 for (int i = 0; i < res.size();i++) { 
        for (auto it = res[i].begin();it != res[i].end(); it++) 
            cout << *it << " "; 
        cout << endl; 
    } 

return 0;
}

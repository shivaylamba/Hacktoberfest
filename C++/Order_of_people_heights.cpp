vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    vector<pair<int,int>> v;

int n=A.size();

for(int i=0;i<n;i++) v.push_back({A[i],B[i]});


sort(v.begin(),v.end());
vector<int> ans(n,0);
for(int i=0;i<n;i++)
{
    int j=0;
    int count=0;
    while(count<=v[i].second)
    {
        if(ans[j]==0) count++;
        j++;
    }
    ans[j-1]=v[i].first;
}
return ans;

}

class Solution {
public:
unordered_map<string,bool> um;
int solve(string a, string b)
{
if(a.compare(b)==0)
    return 1;
else if(a.length()<=1)
    return 0;
int n = a.length();
string key= a + " " + b;
if(um.find(key)!=um.end())
    return um[key];
bool flag = false;
for(int i = 1; i<n;i++){
bool m = solve(a.substr(0,i), b.substr(n-i,i)) && solve(a.substr(i,n-i),b.substr(0,n-i));
bool n = solve(a.substr(0,i), b.substr(0,i)) && solve(a.substr(i,n-i),b.substr(i,n-i));
if(m||n){
    flag = true;
    break;
}
}
um[key]=flag;
return flag;
}

    bool isScramble(string A, string B) {
     int n = A.size();
    int m = B.size();
    if(n!=m)
        return 0;
    if(n==0 && m==0)
        return 1;
    return solve(A,B);
    }
};
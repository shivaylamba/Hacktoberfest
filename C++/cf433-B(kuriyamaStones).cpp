#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n; cin>>n;
    vector<long long int> v1(n+1); 
    vector<long long int> u1(n+1);
    for (int i=1; i<=n; i++){
        long long int uv; cin >> uv;
        v1[i] = uv; u1[i] = uv;
    }

    sort(u1.begin(), u1.end());

    //prefix sums
    for (int ii=2; ii<=n; ii++){
        v1[ii] += v1[ii-1];
        u1[ii] += u1[ii-1];
    }


    int m, type, l, r; cin >>m;
    for (int jjj=0; jjj<m; jjj++){
        cin >> type >> l >> r;

        if (type==1){
            cout << v1[r]-v1[l-1] << endl;
        }else{
            cout << u1[r] - u1[l-1] << endl;
        }
    }
   


}
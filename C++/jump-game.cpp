#include<iostream>
using namespace std;

bool canJump(vector<int>& A) {
    int n = A.size();
    vector<bool> dp(n, false);
    dp[0] = true;
    for(int i = 1; i < n; i++){
        for(int j = i-1; j >= 0; j--){
            if(A[j] >= i-j && dp[j]){
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n-1];
}

int main() {
    vector A{2,3,1,1,4};
    cout<<canJump(A);
}

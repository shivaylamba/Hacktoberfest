#include<bits/stdc++.h>
using namespace std;

int tribonacci(int x){
    if(x == 0 || x == 1)
        return 0;
    
    else if(x == 2 || x == 3) return 1;

    else
    {
        return tribonacci(x-3)+tribonacci(x-2)+tribonacci(x-1);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        cout << tribonacci(x+1) << '\n';
    }
    return 0;
}

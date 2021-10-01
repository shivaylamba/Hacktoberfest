#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return (gcd(b,a%b));
}
int reduced(string s,int a)
{
    int number = 0;
    for(int i=0;i<s.length();i++)
    {
        number = (number*10+s[i])%a;
    }
    return number;
}
int main()
{
    int test_cases;
    cin >> test_cases;
    while(test_cases--)
    {
        int a;
        string b;
        cin >> a;
        cin >> b;
        int num = reduced(b,a);
        cout << gcd(a,num);
    }
}

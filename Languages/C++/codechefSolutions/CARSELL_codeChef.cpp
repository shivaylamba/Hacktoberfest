#include<bits/stdc++.h>
#define MAX 1000000007

using namespace std;


int main()
{
//Omit before Submitting the Code
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" ,"w" , stdout);
#endif

    long long int t;

    cin>>t;

    while(t--){
        long long int n,temp,x,profit;
        vector<long long int> v;

        n=0;
        temp=0;
        x=0;
        profit = 0;


        cin>>n;

        temp=n;
        while(temp--){
            cin>>x;
            v.push_back(x);
        }

        sort(v.begin(),v.end());

        long long int i = v.size(),cont=0,carValue;
        i--;

        for(i ; i>=0 ; i--){
            carValue = v[i] - cont;

            if(carValue<0) carValue = 0;

            profit = ( carValue % MAX  + profit % MAX) % MAX;
            cont++;
        }

        cout<<profit<<"\n";
    }


	return 0;
}
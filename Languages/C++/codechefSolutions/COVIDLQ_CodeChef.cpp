#include<bits/stdc++.h>

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
        long long int n,cont,flag,x;

        n=0;
        cont=6;
        flag=1;

        cin>>n;

        while(n--){
            cin>>x;
            cont++;
            
            if(x==1){

                if(cont<6){
                    flag=0;
                }

                cont=0;
            }

        }

        if(flag){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }


        

    }


	return 0;
}
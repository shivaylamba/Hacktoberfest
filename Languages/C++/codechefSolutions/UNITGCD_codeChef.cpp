#include<bits/stdc++.h>

using namespace std;


int main()
{
//Omit before Submitting the Code
#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" ,"w" , stdout);
#endif
    
    long long int t ;

    cin>>t;

    while(t--){
        long long int n;

        cin>>n;
        
        
        if(n==1){
            cout<<"1"<<"\n"<<"1 1"<<"\n";
        }
        else if(n==2){
            cout<<"1"<<"\n";
            cout<<"2 1 2"<<"\n";
        }
        else{
            // this is because ever page with even number should be read on different days 
            // therefore in n page half will be even
            cout<<n/2<<"\n";
        
            //on first day 3 pages can be read always that are page 1 , 2 , 3 as they are co prime
            cout<<"3 1 2 3"<<"\n";

            long long int i;

            for(i=4;i<n;i = i+2){
                cout<<"2 "<<i<<" "<<i+1<<"\n";
            }

            if(i==n){
                cout<<"1 "<<i<<"\n";
            }
            
        }
        
    }


	return 0;
}
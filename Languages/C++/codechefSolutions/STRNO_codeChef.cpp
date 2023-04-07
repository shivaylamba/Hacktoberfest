//core logic : Every number greater than or equal to 2 , can be written as product of prime numbers
// prime factorization and theorem for  number of divisors of number

//key Points: 
//      1.find prime factorization of a number fast by using square root technique
//      2. find if a number is prime or not ..fastly ..by using square root technique

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
        long long int x,k,flag,contPrime,startPrime;
        
        x=0;
        k=0;
        flag = 1;
        contPrime= 0;
        startPrime = 2;

        cin>>x>>k;

        if(x==1)flag=0;
        
        
        //all or (all - 1)  prime factors by which a number is divisible are present inside its square root range
        long long rootOfX = sqrt(x);
        while(startPrime<=rootOfX){

            while(x%startPrime==0){
                x = x/startPrime;
                contPrime++;
            }

            startPrime++;
            
        }
        
        // this condition is because , suppose after above divison of x by prime number less than its square root
        // if resultant x is prime , than it is only divisibe by 1 and itself
        // hence we have to count x also as it is also a prime divisor
        if(x>1){
            contPrime++;
        }

        if(contPrime>=k && flag){
            cout<<"1"<<"\n";
        }
        else{
            cout<<"0"<<"\n";
        }
    }


	return 0;
}
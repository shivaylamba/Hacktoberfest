    


    //x and y are the values which satisfy this equation 
    //ax+by = gcd(a,b) = gcd(b,a%b)                ----(1)
    //(b)x1+(a%b)y1 =  gcd(a,b)                    from eq 1
    
  
    //since a%b = a-floor(a/b)*b                   ----(2)
    //(b)x1+(a-floor(a/b)*b)y1 = gcd(a,b)
    //(b)x1+ay1-floor(a/b)*by1 = ax+by            from eq 1
    //a(y1)+b(x1-floor(a/b)y1) = ax+by
  
    //comparing the cofficiants
  
  
    //Final Result
    //x = y1;
    //y = x1-floor(a/b)y1


#include<bits/stdc++.h>
using namespace std;



int gcd(int a, int b, int& x, int& y) { 
  
    //base case
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}


int main(){
    int x,y;
    int ans = gcd(3,4,x,y);
    cout<<"GCD is : "<<ans<<"\n";
    cout<<"X : "<<x<<"\n"<<"Y : "<<y<<"\n";
    return 0;
}

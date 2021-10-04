#include <iostream>

int main(){
     int n{};
     int k{};
     std::cout << "enter the value of n" << std::endl;
     std::cin >> n;
     std::cout << "enter the value of k" << std::endl;
     std::cin >> k;

     if (!(n>=k && k>=0)){
          std::cout << "Cannot calculate nCk because condition n >= k >= 0 was not met.";

          return 0;
     }

     if (k<(n-k)){
          k = n-k;
     }
     
     int numerator{1};
     int denominator{1};
     for ( int i=n; i >= k+1; --i ){
          numerator *= i;
     }
     for ( int j=(n-k); j >= 1; --j  ){
          denominator *= j;
     }
     
     std::cout << "The value of nCk: " << numerator/denominator << std::endl;
     
     return 0;
}

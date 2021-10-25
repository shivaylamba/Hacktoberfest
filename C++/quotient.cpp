#include <iostream>
using namespace std;
int main()
 {
   int divisor, dividend, quotient, remainder;
   dividend = 15;
   divisor = 7;
   quotient = dividend / divisor;
   remainder = dividend % divisor;
   cout << "Dividend is " << dividend <<endl;
   cout << "Divisor is " << divisor <<endl;
   cout << "Quotient is " << quotient << endl;
   cout << "Remainder is " << remainder;
   return 0;
}
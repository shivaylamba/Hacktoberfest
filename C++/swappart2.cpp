#include <iostream>
using namespace std;
int main() {
   int a = 10, b = 5;
   a = a+b;
   b = a-b;
   a = a-b;
   cout<<"Value of a is "<<a<<endl;
   cout<<"Value of b is "<<b;
   return 0;
}
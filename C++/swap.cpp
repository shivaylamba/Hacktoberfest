#include <iostream >
using namespace std;
int main() {
   int a = 10, b = 5, temp;
   temp = a;
   a = b;
   b = temp;
   cout<<"Value of a is "<<a<<endl;
   cout<<"Value of b is "<<b;
   return 0;
}
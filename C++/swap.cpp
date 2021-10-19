// first way by introducing a temporary variable
#include <iostream>
using namespace std;
int main()
{
  int a; 
  cout << "Enter first number -";
  cin >> a;
  int b;
  cout << "Enter second number-";
  cin >> b;

  // to display number before swapping
  cout << "before swapping the number:first number" << a << endl;
  cout << ":second number" << b << endl;
  // swapping
  int c;
  c = a; // giving temp variable value of a
  a = b; // giving variable a value of variable b
  b = c; // updating variable b value with previous value of a 
  //displaying the swapped number
  cout << "after swapping first number:" << a << endl
       << "second number" << b;
}
//second way without including any temporary variable

// #include <iostream>
// using namespace std;
// int main(){
//     int a,b;
//     cout<<"Enter first number:"<<endl;
//     cin >>a ;
//     cout<< "Enter second number:"<<endl;
//     cin>>b;
//     // before swapping
//     cout<< "Before swapping : First number-"<< a<<endl << "Second number-"<<b<<endl;
//     //swapping
//     a=a+b; //now a is sum of both  entered numbers
//     b=a-b; //b is equal to previous value of a 
//    a=a-b; // a is now equal to original value of b 
//     cout<< "After swapping : First number-"<< a<<endl << "Second number-"<<b;
//     return 0;
// }

//Write a C++ program to define the concepts of declaring the class, its data members and
member functions. Also write a main () function which declares the objects and uses the
member functions of the class.


#include <stdio.h>
#include<iostream>
using namespace std;
class student
{
// Access specifier
public:
// Data Members
string student_name;
// Member Functions()
void printname()
{
cout << "Student name is: " << student_name;
}
};
int main()
{ // Declare an object of class geeks
student obj1; // accessing data member
obj1.student_name = "Nafis"; // accessing member function
obj1.printname();
return 0;
}

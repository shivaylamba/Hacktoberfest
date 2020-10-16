#include <iostream> 
#include <math.h>
using namespace std; 
  
void areaSquare() 
{ 
    float side;
    cout<<"Enter the side of square"<<endl<<"Side = ";
    cin>>side; 
    float area = side * side; 
    cout<<"Area of the square with side "<<side<<" units "<<"is "<<area<<" sq. units";
    cout<<endl;
} 
  
void areaRectangle()
  
{ 
    float l,b;
    cout<<"Enter the length of rectangle"<<endl<<"Length = ";
    cin>>l; 
    cout<<"Enter the breadth of rectangle"<<endl<<"Breadth = ";
    cin>>b;
    float area = l * b; 
    cout<<"Area of the rectangle with length "<<l<<" units and "<<"breadth "<<b<<" units is "<<area<<" sq. units";
  cout<<endl;
} 

void areaTriangle()
  
{ 
    float a,b,c;
    cout<<"Enter the base of triangle"<<endl<<"Base = ";
    cin>>a; 
    cout<<"Enter the height of triangle"<<endl<<"Height = ";
    cin>>b;
    cout<<"Enter the hypotenuse of triangle"<<endl<<"Hypotenuse = ";
    cin>>c; 
    if (a < 0 || b < 0 || c < 0 ||  
       (a + b <= c) || a + c <= b ||  
                       b + c <= a)  
    {  
        cout << "Not a valid triangle";
      cout<<endl;  
    }
  else
  {
    float s = (a + b + c) / 2;  
    float area = sqrt(s * (s - a) *  (s - b) * (s - c)); 
    cout<<"Area of the triangle with base "<<a<<" units, "<<"height "<<b<<" units and "<<"hypotenuse "<<c<<" units is "<<area<<" sq. units";
cout<<endl;}
} 

void areaCircle() 
{ 
    float r;
    cout<<"Enter the radius of circle"<<endl<<"Radius = ";
    cin>>r; 
    double area = 3.1415926 * r * r; 
    cout<<"Area of the circle with radius "<<r<<" units "<<"is "<<area<<" sq. units";
  cout<<endl;
} 

void areaTrapezium()
  
{ 
    float a,b,h;
    cout<<"Enter the two parallel sides of trapezium"<<endl<<"Side 1 = ";
    cin>>a; cout<<"Side 2 = "; cin>>b;
    cout<<"Enter the height of trapezium"<<endl<<"Height = ";
    cin>>h;   
    float area = 0.5 * (a + b) * h; 
    cout<<"Area of the trapezium with two parallel sides "<<a<<" units, "<<b<<" units and "<<"height "<<h<<" units is "<<area<<" sq. units";
cout<<endl;
} 


int main() 
{ 
  char choice;
do{
    int n;
    cout<<"Area Calculator Menu"<<endl;
    cout<<"1. Area of Square"<<endl;
    cout<<"2. Area of Rectangle"<<endl;
    cout<<"3. Area of Triangle"<<endl;
    cout<<"4. Area of Circle"<<endl;
    cout<<"5. Area of Trapezium"<<endl; 
     
    cout<<"Choose from above"<<endl;
    cin>>n;
    cout<<endl;
    if(n==1)
    areaSquare();
   else if(n==2)
    areaRectangle();
   else if(n==3)
    areaTriangle();
   else if(n==4)
    areaCircle();
   else if(n==5)
    areaTrapezium();  
    else
       cout<<"Not a valid number"<<endl;
  cout<<"Want to calculate more?"<<endl<<"If yes then press Y OR y"<<endl<<"If no then press any key";
  cout<<endl<<"Choice = "; cin>>choice;cout<<endl;
} while((choice == 'Y')|| (choice == 'y'));


}

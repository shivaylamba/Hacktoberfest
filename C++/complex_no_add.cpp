
#include<iostream>

// this is a simple program to add 2 complex numbers 
// please use c++ 14 version compliers for running this code 


using namespace std ;

class complex 
{
int x,y;

public:
void getdata(void);
void disp_data(void);
void add(complex c1 , complex c2 );
};

void complex::getdata()
{
cout<<"enter the value of x ";
cin>>x;

cout<<" enter the value y";
cin>>y;

}

void complex::disp_data()
{
  cout<<"\n the complex number entered is "<<endl;
  cout<<x<<"+i"<<y<<endl;
}

void complex::add(complex c1 , complex c2 )
{
  x= c1.x + c2.x ;
  y= c1.y + c2.y ;

  cout<<" \n the addition of the following 2 complex numbers is "<<endl;
  cout<<x<<"+i"<<y<<endl ;
  
}

int main()
{
  complex c1,c2,c3 ;

  c1.getdata();
  c2.getdata();
  c1.disp_data();
  c2.disp_data();
  c3.add(c1,c2);



  return 0 ;  
}

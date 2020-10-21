#include<simplecpp>
#include<math.h>
main_program{
//Write your code here           //Here we r finding the cube root of 3 then as you can see that when we take xl==0 then
double xl=0,xr=3,xm,alpha=0.00001; // f(xl)=(-ve) so now we need to take other xr such that f(xr)=(+ve) so xr==2
int flag=0;                              // our function is x^3-3 which is equal to 0 then f(x)=x^3-3 we can find out our soln that we need
                          //here we need to take the alpha as so much much small becoz we wants the roots soo much accurate
while((xr-xl)>=alpha)    // here xm is the med point between xl and xr so that we can decrease our lenth between in such a way
{ xm=(xl+xr)/2;                  //we get our karib karib result of cube or root of any number
  if(((xl*xl*xl-3>0) && (xm*xm*xm-3>0)) || ((xl*xl*xl-3<0) && (xm*xm*xm-3<0))) // basically this only the bisection method
    {xl=xm;
     }
  else
  {xr=xm;
  }flag++;
  cout << "At term "<< flag << "its value is " << xl << '\n';
}
  cout << '\n' << "Final value is; "<< xl ;
  cout << '\n' << "Final value is;" << xl ;
}

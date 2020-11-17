#include<stdio.h>
#include<math.h>
void main()
{float a,y,h,end; 
 printf("\nEnter Xo:");
 scanf("%f",&a);
 printf("\nEnter Yo:");
 scanf("%f",&y);
 printf("\nEnter h:");
 scanf("%f",&h);
 printf("\nEvaluate upto X=");
 scanf("%f",&end);
 int n=0;
 for(float x=a;x<end;x+=h)
 {
 n++;
     y=y+h*( (y*y)-x );
 printf("Y%d= %f\n",n,y);
}
 }
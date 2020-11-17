#include<stdio.h>
#include<ctype.h>
void main()
{
char f[100];
float a,y,h,end,z;
printf("Enter f(x,y):");
scanf("%s",f);
printf("\nEnter Xo:");
scanf("%f",&a);
printf("\nEnter Yo:");
scanf("%f",&y);
printf("\nEnter h:");
scanf("%f",&h);
printf("\nEvaluate upto Xo=");
scanf("%f",&end);
for(float x=a;x<end;x+=h)
{
    if(f[0]='-')
       z=0;
    else
       z=1;
    for(int j=0;f[j]!='\0';j++)
    {   
        if(isdigit(f[j])>0)
        {
           float m=1,l=0;
           do{
              int k=f[j]-48;
              l=l*m+k;
              m*=10;
              j++;
             }while(isdigit(f[j])>0);
           z=z*l;
        }
        if(f[j]=='x')
        {
           f[j]=x;
        }
        if(f[j]=='y')
        {
           f[j]=y;
        }
        if(f[j]=='+')
        {
           z=z+f[j+1];
        }
        if(f[j]=='-')
        {
           z=z-1;
        }
        if(f[j]=='/')
        {
           z=z/f[j+1];
        }
        else
           z=z*f[j];
    }
    y=y+h*(z);
}
printf("Hence, Yn= %f",y);
}

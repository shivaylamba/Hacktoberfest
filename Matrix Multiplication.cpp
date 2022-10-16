#include<iostream>
using namespace std;
float arr[3][3],arr2[3][3],arr3[3][3]={0},arr4[3][3];
int l=0;
 bool orthogonal_array(float arr[3][3])
 {for(int i=0;i<3;i++)
{for(int j=0;j<3;j++)
arr2[i][j]=arr[j][i];
}
for(int i=0;i<3;i++)
{for(int j=0;j<3;j++)
{for(int k=0;k<3;k++)
     arr3[i][j]+=arr[i][k]*arr2[k][j];}                 
     	 }
for(int i=0;i<3;i++)
{for(int j=0;j<3;j++)    	
{ if(i==j)
   arr4[i][j]=1;
   else
   arr4[i][j]=0;
 } 
} 
for(int i=0;i<3;i++)
{for(int j=0;j<3;j++)    	
{ if(arr3[i][j]==arr4[i][j])
l++;
}
}
if(l==9)
return true;
else
return false;
 }
int main()
{
cout<<"Enter the elements of 3x3 matrix"<<endl;
for(int i=0;i<3;i++)
{for(int j=0;j<3;j++)
{printf("Element at [%d][%d] position is:",i+1,j+1);
scanf("%f",&arr[i][j]);
}   
}  
if(orthogonal_array(arr))
cout<<"Given Matrix is orthogonal"<<endl;
else
cout<<"Given Matrix is not Orthogonal"<<endl;
return 0;}
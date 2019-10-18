#include <iostream>
using namespace std;

int main() 
{
    int s, vol, surface_area;	
    	
    cout<<"Enter the side length of a cube : ";
    cin>>s;
    	
    vol = s*s*s;
    surface_area = 6*s*s;
    	
    cout<<endl;
    cout<<"The volume of the cube is : "<< vol <<endl;
    cout<<"The surface area of the cube is : "<< surface_area <<endl;
        
    return 0;
}

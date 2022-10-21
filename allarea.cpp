#include<bits/stdc++.h>
#define pi 3.14
using namespace std;
class allarea
{
    private:
    int side;
    int length , breadth;
    int radius ;
    public:
    void setside(int s)
    {
        side=s;
    }
    void setlengthbreadth(int l, int b)
    {
        length=l;
        breadth=b;
    }
    void setradius(int r)
    {
        radius=r;
    }
    int getareasquare()
    {
        return side*side;
    }
    int getarearectangle()
    {
        return length*breadth;
    }
    float getareacircle()
    {
        return ( pi *radius*radius);
    }

};
int main()
{
    allarea a1;
    int a;
    int c,d;
    cout<<"1. area of rectangle "<<endl;
    cout<<"2.area of square"<<endl;
    cout<<"3.area of circle"<<endl;
    cout<<"4. exit"<<endl;
    cin>>a;
    switch(a)
    {
        case 1:
        cout<<"enter length and breadth :";
        cin>>c>>d;
        a1.setlengthbreadth(c,d);
        cout<<"area of rectangle is "<<a1.getarearectangle();
        break;



        case 2:
        cout<<"enter side of square :";
        cin>>c;
        a1.setside(c);
        cout<<"area of square is "<<a1.getareasquare();
        break;


        case 3:
        cout<<"enter radius of circle :";
        cin>>c;
        a1.setradius(c);
        cout<<"area of circle  is "<<a1.getareacircle();
        break;


        default:
        cout<<"not allowed";
        return 0;

    }
}
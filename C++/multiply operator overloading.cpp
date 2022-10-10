
#include<iostream>

using namespace std;

class matrix
{

    public:
    int a[3][3];

    matrix()//default constructor
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                a[i][j]=0;
            }
        }
    }
    void set()// to set matrix elements
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<"\n Enter "<<i<<","<<j<<" element=";
                cin>>a[i][j];
            }
        }
    }
    void show()// to show matrix elements
    {
        cout<<"\n Matrix is=\n";
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {

                cout<<a[i][j]<<",";
            }
            cout<<"\n";
        }
    }
    /*
    binary * operator will require one more arg, since it is a binary operator
    one arg is the object itself that will call it, other will be passed as arg(in this case x). also this will return a matrix object
    */
    matrix operator*(matrix x)// overloading * for multiplication
    {
        matrix c;// this will hold our result
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                c.a[i][j]=0;
                for(int k=0;k<3;k++)
                {
                    c.a[i][j]=c.a[i][j]+a[i][k]*x.a[k][j];
                }
            }
        }
        return(c);

    }
};

int main()
{
    matrix a,b,c;
    a.set();
    b.set();
    c=a*b;
    a.show();
    b.show();
    c.show();
}

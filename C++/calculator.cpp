#include <iostream>

using namespace std;

int main()
{
    float a,b;
    string op;

    cout<<"1.Enter Your First Number"<<endl;
    cin>>a;
    cout<<""<<endl;
    cout<<"2.Enter Your Second Number"<<endl;
    cin>>b;
    cout<<""<<endl;
    cout<<"3.Enter Your Operation System"<<endl;
    cin>>op;
    cout<<""<<endl;
    if(op=="+"){
        cout<<"Your Answer Is "<<a+b<<endl;
    }
    else if(op=="-"){
        cout<<"Your Answer Is "<<a-b<<endl;
    }
    else if(op=="/"){
        cout<<"Your Answer Is "<<a*b<<endl;
    }
    else if(op=="*"){
        cout<<"Your Answer Is "<<a/b<<endl;
    }


    return 0;
}

#include<iostream>
using namespace std;
int main(){
    int d1;
    int m1;
    int y1;
    int d2;
    int m2;
    int y2;
    cout<<"Enter Todays Date :";
    cout<<"First enter day :";
    cin>>d1;
    cout<<"enter month :";
    cin>>m1;
    cout<<"enter year :";
    cin>>y1;
    cout<<"now Enter birthdate :";
    cout<<"First enter day";
    cin>>d2;
    cout<<"enter month :";
    cin>>m2;
    cout<<"enter year :";
    cin>>y2;
    int rd ,md,yd;
     rd = d1-d2;
     md = m1-m2;
     yd = y1-y2;
    cout<<"your age is :"<<rd<<'/'<<md<<'/'<<yd<<'.';
};

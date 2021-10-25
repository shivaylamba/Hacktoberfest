#include <iostream>

using namespace std;

int main()
{
    float bmi,w,h;
    cout << "Enter your age: ";
    cin >> w;
    cout << "Enter your height in inches: ";
    cin >> h;
    bmi = (w*703)/(h*h);
    cout <<"Your bmi is: " << bmi << endl;
    
    if(bmi>25)
    cout<<"Overweight";
    else if(bmi<25 && bmi>18.5)
    cout<<"Optimal";
    else
    cout<<"Underweight";

    return 0;
}

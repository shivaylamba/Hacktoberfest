
#include <iostream>

using namespace std;

int main()
{
    int number, temp, x, reverse=0;
    cin >> number;

    temp = number;

    while(number!=0){
        x = number%10;
        reverse = (reverse*10)+x;
        number=number/10;
    }

    if (temp == reverse)
         cout << "True";
     else
         cout << "False";

    return 0;
}

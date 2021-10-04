#include <iostream>
#include <limits>
using namespace std;
void binary(int number) {
    int sisa, hasil;
    if (number <= 1) {
        cout << number;
        return;
    }
    sisa = number % 2;
    hasil = number / 2;
    binary(hasil);
    cout<<sisa;
}
int main()
{
	
	cout<<endl<<endl<<" Decimal to binary conversion";
	cout<<endl<<" ========================="<<endl<<endl;
	int decimal;
	cout<<" Enter decimal (10): ";
    cin>>decimal;
    if (cin.good()) {
        cout << endl << " Result: ";
        binary(decimal);
        cout << endl << endl;
    } else {
        cout << endl << " Please enter a valid number!";
        cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

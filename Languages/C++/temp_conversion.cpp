#include<iostream>
using namespace std;

int main()
{
   float fahrenheit, celsius;
   char select;

   cout << "Select from following selects:" << endl;
   cout << "1. celsiussius to fahrenheitenheit." << endl;
   cout << "2. fahrenheitenheit to celsiussius." << endl;
   cin >> select;

   //select for converting celsiussius into fahernheit
   if (select == '1')
   {
      cout << "Temperature in celsiussius: ";
      cin >> celsius;

      fahrenheit = (1.8 * celsius) + 32.0; //temperature conversion formula
      cout << "\nTemperature in fahrenheitenheit is: " << fahrenheit << " F" << endl;
   }
   //select for converting fahrenheitenheit into celsiussius
   else if (select == '2')
   {
      cout << "Temperature in fahrenheitenheit: ";
      cin >> fahrenheit;

      celsius = (fahrenheit - 32) / 1.8; //temperature conversion formula
      cout << "\nTemperature in celsiussius is : " << celsius << " C" << endl;
   }
   else
      cout << "Enter correct input" << endl;

   return 0;
}

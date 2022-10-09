#include <iostream>
using namespace std;

int main() {

  int i, n;
  float array[100];

  cout << "Enter total number of elements(1 to 100): ";
  cin >> n;
  cout << endl;

  for(i = 0; i < n; ++i) {
    cout << "Enter Number " << i + 1 << " : ";
    cin >> array[i];
  }

  // Loop to store largest number to arr[0]
  for(i = 1;i < n; ++i) {

    // Change < to > if you want to find the smallest element
    if(array[0] < array[i])
      array[0] = array[i];
  }

  cout << endl << "Largest element = " << array[0];

  return 0;
}
#include <iostream>

using namespace std;

int secondLargest(int arr[], int n) {
  int largest = arr[0];
  int secondLargest = arr[1];
  for (int i = 1; i < n; i++) {
    if (arr[i] > largest) {
      secondLargest = largest;
      largest = arr[i];
    } else if (arr[i] > secondLargest && arr[i] != largest) {
      secondLargest = arr[i];
    }
  }
  return secondLargest;
}

int main(){
  int arr[7] = {1,2,3,4,5,6,7};
  int n = sizeof(arr) / sizeof(arr[0]);
  int secondLargestInt = secondLargest(arr, n);
  cout << "Second largest element is: " << secondLargestInt << endl;

  return 0;
}
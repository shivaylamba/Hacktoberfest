#include <iostream>
using namespace std;
int main()
{
  // Pointer initialization to null
  int *m = NULL;

  // Request memory for the variable using new operator
  m = new (nothrow) int;
  if (!m)
    cout << "allocation of memory failed\n";
  else
  {
    // Store value at allocated address
    *m = 29;
    cout << "Value of m: " << *m << endl;
  }
  // Request block of memory using new operator
  float *f = new float(30.15);
  cout << "Value of f: " << *f << endl;
  // Request block of memory of size
  int size = 5;
  int *arr = new (nothrow) int[size];
  if (!arr)
    cout << "allocation of memory failed\n";
  else
  {
    for (int i = 0; i < size; i++)
      arr[i] = i + 1;

    cout << " The value store in block of memory: ";
    for (int i = 0; i < size; i++)
      cout << arr[i] << " ";
  }

  // freed the allocated memory
  delete m;
  delete f;
  // freed the block of allocated memory
  delete[] arr;

  return 0;
}
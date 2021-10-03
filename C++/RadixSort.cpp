// Radix Sort
// Time Complexity: O(nk)
// Space Complexity: O(n+k)

#include <iostream>
#include <list>
#include <cmath>
using namespace std;

// Function to print array
void print(int *array, int size)
{
   for (int i = 0; i < size; i++)
      cout << array[i] << " ";
   cout << endl;
}

// Sorting Function
void radixSort(int *arr, int n, int max)
{
   int i, j, m, p = 1, index, temp, count = 0;
   list<int> pocket_list[10]; //radix of decimal number is 10
   for (i = 0; i < max; i++)
   {
      m = pow(10, i + 1);
      p = pow(10, i);
      for (j = 0; j < n; j++)
      {
         temp = arr[j] % m;
         index = temp / p; //find index for pocket_list array
         pocket_list[index].push_back(arr[j]);
      }
      count = 0;
      for (j = 0; j < 10; j++)
      {
         //delete from linked lists and store to array
         while (!pocket_list[j].empty())
         {
            arr[count] = *(pocket_list[j].begin());
            pocket_list[j].erase(pocket_list[j].begin());
            count++;
         }
      }
   }
}

// Main Function
int main()
{
   int n, max;
   cout << "Enter the number of elements: ";
   cin >> n;
   cout << "Enter the maximum digit of elements: ";
   cin >> max;
   int arr[n]; //create an array with given number of elements
   cout << "Enter elements:" << endl;
   for (int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }
   cout << "Array before Sorting: ";
   print(arr, n); // Printing array before sorting

   radixSort(arr, n, max); // Sorting the array using bucket sort

   cout << "Array after Sorting: ";
   print(arr, n); // Printing array after sorting
}
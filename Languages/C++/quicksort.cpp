#include <iostream>
 
void PrintArray(int *array, int n) {
  for (int i = 0; i < n; ++i)
    std::cout << array[i] << " " << std::flush;
  std::cout << std::endl;
}
 
inline void Swap(int &a, int &b){
    int k = a;
    a = b;
    b = k;
}
 
//reload rand to produce random number in a fixed range
inline int rand(int p, int q){
    int size = q - p + 1;
//    srand(time(NULL));
    return (p + rand() % size);
}
int Partition(int arr[], int lo, int hi){
    //produce ramdom subscript
    int t = rand(lo, hi);
    Swap(arr[t], arr[hi]);
 
    int index = lo - 1;
    int key = arr[hi];
    for(int i = lo ; i < hi; i++){
        if(arr[i] <= key)
            Swap(arr[++index], arr[i]);
    }
    Swap(arr[++index], arr[hi]);
    return index;
}
void QuickSortHelper(int arr[], int lo, int hi){
    if(lo < hi){
        int index = Partition(arr, lo, hi);
        QuickSortHelper(arr, lo, index-1);
        QuickSortHelper(arr, index+1, hi);
    }
}
 
void QuickSort(int arr[], int arr_size){
    QuickSortHelper(arr, 0, arr_size-1);
}
 
 
int main() {
  int array[] = {94, 42, 50, 95, 333, 65, 54, 456, 1, 1234};
  int n = sizeof(array)/sizeof(array[0]);
 
  std::cout << "Before Quick Sort :" << std::endl;
  PrintArray(array, n);
 
  QuickSort(array, n);
 
  std::cout << "After Quick Sort :" << std::endl;
  PrintArray(array, n);
  return (0);
}
 

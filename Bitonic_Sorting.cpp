#Bitonic Sorting in C++

#include<iostream>
using namespace std;
void bitonicSeqMerge(int a[], int start, int BseqSize, int direction) {
   if (BseqSize>1){
      int k = BseqSize/2;
      for (int i=start; i<start+k; i++)
      if (direction==(a[i]>a[i+k]))
      swap(a[i],a[i+k]);
      bitonicSeqMerge(a, start, k, direction);
      bitonicSeqMerge(a, start+k, k, direction);
   }
}
void bitonicSortrec(int a[],int start, int BseqSize, int direction) {
   if (BseqSize>1){
      int k = BseqSize/2;
      bitonicSortrec(a, start, k, 1);
      bitonicSortrec(a, start+k, k, 0);
      bitonicSeqMerge(a,start, BseqSize, direction);
   }
}
void bitonicSort(int a[], int size, int up) {
   bitonicSortrec(a, 0, size, up);
}
int main() {
   int a[]= {5, 10, 51, 8, 1, 9, 6, 22};
   int size = sizeof(a)/sizeof(a[0]);
   printf("Original array: \n");
   for (int i=0; i<size; i++)
   printf("%d\t", a[i]);
   bitonicSort(a, size, 1);
   printf("\nSorted array: \n");
   for (int i=0; i<size; i++)
   printf("%d\t", a[i]);
   return 0;
}

#DESCRIPTION
#The bitonic sort is a parallel sorting algorithm that is created for best implementation and has optimum usage with hardware and #parallel processor array.
#It is not the most effective one though as compared to the merge sort. But it is good for parallel implementation. This is due to #the predefined comparison sequence which makes comparisons independent of data that are to be sorted.
#For bitonic sort to work effectively the number of elements should be in a specific type of quantity i.e. the order 2^n
#One major part of the bitonic sort is the bitonic sequence which is a sequence whose elements value first increases and then #decreases.
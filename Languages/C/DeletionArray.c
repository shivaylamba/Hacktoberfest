#include<stdio.h>
int main() {
   int arr[]={2,3,1,6,7};
   int num=sizeof(arr)/sizeof(arr[0]);
   int i, loc;
   printf("\n location of the element to be deleted :");
   scanf("%d", &loc);

   while (loc < num) {
      arr[loc - 1] = arr[loc];
      loc++;
   }
   num--;
   for (i = 0; i < num; i++)
      printf(" %d", arr[i]);
    getch();
   return (0);
}

// arr - input array
// n - size of array

void SortZeroesAndOne(int arr[], int n){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Update in the given array itself. Don't return or print anything.
     * Taking input and printing output is handled automatically.
     */
  int p=0;
  int i=1,c=1;
  while(p<n&&c<n)
  { int temp;
    if(arr[p]>arr[c])
    {
      temp=arr[p];
      arr[p]=arr[c];
      arr[c]=temp;
      
      p++;
    }
   else if(arr[p]==arr[c])
   { if(arr[p]==0){
     c++;
     p++;}
    else
      c++;
   }
   else if(arr[p]<arr[c])
   {
     p++;
     c++;
   }
   
    

  }
}

// input1 - first array
// input2 - second array
// size1 - size of first array
// size2 - size of second array
//#include<climits>

void intersection(int input1[], int input2[], int size1, int size2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Print the output and don't return it.
     * Taking input is handled automatically.
     */
//int n1,n2;
  //if(size1<=size2)
  //{
   // n1=size1;
    //n2=size2;
    long long int i=0;
  while(i<size1)
  {
    long long int j=0;
    while(j<size2)
    {
      if(input1[i]==input2[j])
      { 
        input2[j]=-2147483648;
        cout<<input1[i]<<endl;
        break;
      }
      j++;
    }
    i++;
  }
 // }
    
  /*else
  {
    n1=size2;
    n2=size1;
    int i=0;
  while(i<n1)
  {
    int j=0;
    while(j<n2)
    {
      if(input2[i]==input1[j])
      {
        cout<<input2[i]<<endl;
        break;
      }
      j++;
    }
    i++;
  }
  }*/
  

}

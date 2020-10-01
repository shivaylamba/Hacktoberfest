#include <stdio.h>


/**************** Binary String Function **************
* This function takes a pointer to a char array, an int representing the
* size of the array, an int representing a number to covert as aruments
* then converts the int using bitwise operations. Returns a string of ones
* and zeros. See in code comments for more on how this is done.
*******************************************************/

int binaryString(char *strPtr, int strLength, int num)
{  
  // Variables used
  // i is for the for loop
  // temp is so we can do bitwise operations on the int passed in without  changing its value
  // count is so we can access the correct element in the array
  int i, temp;
  int count = 0;

    // Start iterating over the array from strLength - 1. We do this so that 
    // we can right shift the number passed one less time than the amount of 
    // bits in the string it should fill, and compare the bit on the far left to
    // the bits of the number one.
    for(i = strLength - 1; i >= 0; i--)
	{
	  // Stores the number right shifted (>>) i times
	  // Pushes the bit we want to check to the end.
	  temp = num >> i;
	  
          // Compares the bits of the stored number to binary 1
          // if the bit at that location is significant, when 
          // it is pushed to the end, & 1 will evaluate to true.
  	  if(temp & 1)
	  {
	    *(strPtr + count) = '1'; // changing the value of the array at the location we are checking for to 1 if true
	  }
	  else
  	  {
	    *(strPtr + count) = '0'; // opposite if false
	  }

	  count++; // incrementing to the next location in our array to return
	}
	
  *(strPtr+count) = '\0'; // Stops program from priting garbage value at the end
  return 0;
}


int main()
{
  int ints[10]; // populated this with 0-9, feel free to populate as you wish
  int i;
  
  for(i = 0; i < 10; i++)
  {
    ints[i] = i;
    char binstring[32];
    char *binPointer = binstring;
    binaryString(binPointer, 32, ints[i]);

    printf("[ %d in binary is:\t%s ]\n", ints[i], binstring);
    
  }



}

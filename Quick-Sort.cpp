#include<iostream>
#include "Solution.h"
using namespace std;


int  partition(int input[], int start, int end){
   int i=start;
   int j=end;
   int pi = input[start];
   int count =0;
    for(int i =start+1; i<=end; i++){
        if(input[i]<=pi){
            count++;
        }

    }
    //swap after getting correct position of pivot pi
    int pos=start+count;

    int temp = input[pos];
    input[pos] = input[start];
    input[start]= temp;
    while(i<start+count && j>start+count){
        if(input[i]<=pi){
            i++;
        }
        else if(input[j]>pi){
                j--;
        }
        else{
            int temp = input[i];
            input[i]= input[j];
            input[j]= temp;
            i++;
            j--;

        }

    }
    return pos;



}
void quickSort(int input[], int start, int end)
	{
    		// your code goes here 
      if(start>=end){
          return;

      }
       int pi =partition(input, start, end);
       quickSort(input, start, pi-1);
       quickSort(input, pi+1, end);

	}
	void quickSort(int input[], int size)
	{
    		quickSort(input, 0, size - 1);
	}




int main(){
    int n;
    cin >> n;

    int *input = new int[n];

    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }

    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }

    delete [] input;

}

#include <stdio.h>

int main(){
	int size,array[35];
	printf("Enter the size of array..");
	scanf("%d",&size);
	printf("Enter the elements..\n");
	for(int i=0;i<size;i++){
		scanf("%d",&array[i]);
	}
	for(int i=0,j=0;j<size;j++){
		int key = array[j];
		i = j -1;
		while(i>=0 && array[i]>key){
			array[i+1] = array[i];
			array[i] = key;
			i --;
		}
	}
	printf("The sorted array is ..\n");
	for(int i=0;i<size;i++){
		printf("%d ",array[i]);
	}
	return 0;
}

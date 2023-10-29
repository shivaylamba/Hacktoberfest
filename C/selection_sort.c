#include <stdio.h>

void swap(int *min, int *elem){
    int min_temp = *min;
    *min = *elem;
    *elem = min_temp;
}

int main(){
    int *curmin;
    int array[10] = {74, 21, 87, 45, 32, 68, 95, 10, 53, 29};
    for (int i = 0; i < 9; i++){
        curmin = &array[i];
        for (int j = i+1; j < 10; j++){
            if (array[j] < *curmin){
                curmin = &array[j];
            }
        }
        if (*curmin != array[i]){
            swap(curmin,&array[i]);
        }
    }
    printf("sorted array: ");
    for (int i = 0; i < 10; i++){
        printf("%d ", array[i]);
    }
}

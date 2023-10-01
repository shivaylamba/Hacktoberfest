#include<stdio.h>
int linear_search(int z){
    int a[]={5,10,15,20,20,25,30,35,40,45,50};


    for(int i=0;i<10;i++){
        if(z==a[i]){
            printf("Entered Number found at %d position",i+1);
        }
    }
    printf("Entered Number not found");
    return -1;
}
int main(){
    printf("You can search any number from table of 5 from 5 to 50\n");
    printf("Enter a number");
    int n;
    scanf("%d",&n);
    linear_search(n);

    return 0;

}

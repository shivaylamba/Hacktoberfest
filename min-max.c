#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct result{
    int max;
    int min;
};
typedef struct result res;


res min_max_dc(int A[],int lb,int ub,res r1,int *cost1){
    if(lb == ub){
        r1.max = r1.min = A[lb];
        //printf("%d %d\n",r1.max, r1.min);
        (*cost1)+=2;
    }else if(lb == (ub-1)){
        if(A[lb]<A[ub]){
            r1.min = A[lb];
            r1.max = A[ub];
        }else{
            r1.min = A[ub];
            r1.max = A[lb];
        }
        //printf("%d %d\n",r1.max, r1.min);
        (*cost1)+=2;
    }
    else{
        res r_left,r_right;
        int mid = (lb+ub)/2;

        r_left = min_max_dc(A,lb,mid,r_left,cost1);
        r_right = min_max_dc(A,mid+1,ub,r_right,cost1);

        if(r_left.min<r_right.min)
            r1.min = r_left.min;
        else
            r1.min = r_right.min;

        if(r_left.max>r_right.max)
            r1.max = r_left.max;
        else
            r1.max = r_right.max;

        //printf("%d %d\n",r1.max, r1.min);
    }

    return r1;
}

res min_max_iterative(int A[],int lb,int ub, int *cost){

    res r0;
    int min,max,i;
    min = max = 0;
    for(i=lb+1;i<ub;i++){
        if(A[i]<A[min]){
            min = i;
        }else if(A[i]>A[max]){
            max = i;
        }
        (*cost)+=2;
    }
    r0.min = A[min];
    r0.max = A[max];

    return r0;
}

int main(){

    int n,i;
    printf("ENTER THE NO. OF ELEMENTS: ");
    scanf("%d",&n);
    int A[n];
    srand(time(0));
    for(i=0;i<n;i++){
        A[i] = rand()%1000;
    }
    printf("\n ARRAY GIVEN IS: \n\t");
    for(i=0;i<n;i++){
        printf("%d\t",A[i]);
    }
    printf("\n");

    int cost=0;

    //USING ITERATIVE METHOD
    printf("USING ITERATIVE METHOD:- \n");
    res r0 = min_max_iterative(A,0,n,&cost);

    printf("THE MAXIMUM ELEMENT IS: %d \n",r0.max);
    printf("THE MINIMUM ELEMENT IS: %d \n",r0.min);
    printf("THE COST IS: %d\n",cost);

    int cost1 = 0;
    //USING DIVIDE AND CONQUER METHOD
    printf("USING DIVIDE AND CONQUER METHOD:-\n");
    res r1 = min_max_dc(A,0,n-1,r1,&cost1);

    printf("THE MAXIMUM ELEMENT IS: %d \n",r1.max);
    printf("THE MINIMUM ELEMENT IS: %d \n",r1.min);
    printf("THE COST IS: %d",cost1);

    return 0;
}
